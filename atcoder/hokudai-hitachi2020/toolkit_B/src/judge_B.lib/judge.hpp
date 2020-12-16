#ifndef JUDGE_HPP 
#define JUDGE_HPP

#include<iostream>
#include <vector>
#include <map>
#include <stack>
#include "judge_B.lib/graph.hpp"
#include "judge_B.lib/vehicle.hpp"
#include "judge_B.lib/order.hpp"
#include "judge_B.lib/energy.hpp"
#include "judge_B.lib/log.hpp"

class judge{
	public:
		
		graph<edge> g;//グラフ構造体
		std::vector<vehicle> vehicles;//EVの構造体の配列
		std::vector<std::vector<order> > orders;//運搬依頼(Order)の配列
		std::vector<std::vector<energy> > energies;//エネルギー変化のシナリオ（次にどのぐらいの電力が充電されるのか)
		
		size_t N,M;//グラフの頂点数、辺数
		size_t Daytype,N_nano;
		size_t N_vehicle;//EVの数
		size_t T_now=0;//現在の時刻(Time_step)
		size_t num_orders=0;//現在の注文数
		size_t N_sol;//回答回数

		
		size_t T_last;//オーだが発生する最終時刻
		size_t T_max;// 処理最終時刻
		size_t N_div,N_pattern,sigma_ele;
		size_t Delta_event;
		double p_event;
		std::vector<std::vector<int> > pw;
		
		size_t C_Init_Grid,C_Max_Grid;
		int V_Max_Grid;
		size_t C_Init_EV,C_Max_EV;
		int V_Max_EV;
		size_t N_Max_Trans;
		size_t Delta_move;
		double p_trans_const;
		size_t P_trans;
		double Gamma;
		int S_ele_ref,S_trans_ref;



		//出力用保存変数
		std::vector<size_t> u_output,v_output,c_output;
		std::vector<size_t> x_output,type_output,c_max_output,c_init_output;
		std::vector<size_t> pos_output;


		//充電・放電保存
		std::stack<energy> info_from_grid, info_to_grid; 
		std::stack<energy> info_day;
		
		//外部仕様エネルギー合計
		unsigned long int sum_out_charge =  0; // ナノグリッド以上の充電



		std::vector<order> now_orders;

		double transport_score();//運搬スコア関数
	  	double electricity_score();//電力スコア関数



		void init_input(FILE *fp);//FILEを読み必要な構造体などを作成する関数。
		void copy_sol( judge &J, int sol );

		//Check of valids
		bool valid_input();//各ステップで必要な読み込みをチェックし、命令関数を呼び出す関数。
		bool valid_move(size_t id , size_t v);//move命令の内容をチェックし、動作を行う関数。
		bool valid_charge(size_t id, int amount);//charge_from_grid命令をチェックし、実行する関数。
		bool valid_discharge(size_t id, int amount); // charge_to_grid命令をチェックし、実行する関数。
		bool valid_pickup(size_t order_id, size_t vehicle_id);//pick up命令をチェックし、実行する関数。

		bool valid_end_time();//充電・放電命令をまとめて処理する関数。


		bool next_time_step();//次のタイムステップへ変化を実行する関数。

		//print
		//1 timestep毎に
		void print_all(FILE *fp);// output by 1-step 以下のものを順に出力
		void print_rest_energy(FILE *fp);//nano grid
		void print_vehicle(FILE *fp);//print the state of vehicle
		void print_Order(FILE *fp);//print the rest orders	

		void print_Initial_Output(FILE *fp);//固定パラメータ出力



	
};


//A B共通関数の定義

double judge::transport_score(){
	double score = 0;

	for(order o : now_orders ){
		if(o.end_time < 0){
			score -= P_trans;
			continue;
		}
		double T_wait = (o.end_time - o.start_time);
		score += T_max - T_wait;
	}

	return score;
}

double judge::electricity_score(){
	double score = 0;

	for(vehicle v : vehicles){
		score += v.cap;
	}

	for(node n : g.nodes){
		score += n.cap;
	}

	score -= Gamma*sum_out_charge;
	return score;
}

bool judge::valid_move(size_t id , size_t v){//自動車番号、行き先

	position pos = vehicles[id].pos;
	if( pos.on_vertex() ){
		size_t now = pos.to;//現在地
		if( pos.distance == 0 ){
			now = pos.from;
		}
		//nowがvの辺をもつかチェック
		int edge_id = g.find(now, v);

		if( edge_id == -1 ){//error
			DEBUG("can not move %zu to %zu", now + 1, v + 1);
			return false;
		}else{
			if( !vehicles[id].consume(Delta_move) ) return true;//エネルギーを消費し、足りない場合は終了する。
			edge e = g[now][edge_id];//次に使う辺を選択
			//１動く
			position next(now,v,1,e.cost);
			vehicles[id].set_position(next);
		}
	}else{//辺の上にいる
		if( pos.from == v ){
			if( !vehicles[id].consume(Delta_move) ) return true;
			vehicles[id].pos.distance--;
		}else if(pos.to == v ) {
			if( !vehicles[id].consume(Delta_move) ) return true;
			vehicles[id].pos.distance++;
		}else{
			INFO("invalid current destination %zu", v + 1);
			return false;
		}
	}

	//荷物を下ろす
	if( vehicles[id].pos.on_vertex() ){//頂点上にいるか判別
		for(auto it=vehicles[id].orders.begin(); it != vehicles[id].orders.end() ;  ){
			if( now_orders[*it].end_time != -1 ){
				it++;	
				continue; //既に届けている
			}

			if( now_orders[*it].to == vehicles[id].now_vertex() ) {
				now_orders[*it].end_time = T_now;
				it = vehicles[id].orders.erase(it);//次のイテレータを示す。
				num_orders--;
			} else {
				it++;
			}
		}
	}
	return true;
}



//charge from grid
bool judge::valid_charge(size_t id, int amount){
	position &pos = vehicles[id].pos;
	// 頂点にいない場合充電不可
	if (!pos.on_vertex()) {
		INFO("EV: %d is not on node", pos.now_vertex());
		return false;
	}
	// 充電量が正でない場合不可
	if (amount <= 0) {
		INFO("charge: %d is not positive", amount);
		return false;
	}
	// 頂点にいる場合は、車がいる頂点の情報
	int vertex_id = pos.now_vertex();
	auto &current_node = g.nodes[vertex_id];

	// EVが頂点にない場合も充電不可
	if ( !current_node.is_grid() ) {
		INFO("node: %d is not nano grid", vertex_id);
		INFO("type: %d", current_node.type);
		return false;
	}
	//充電量が一ターンを超えているとき
	if ( amount > V_Max_EV ) {
		INFO("charge: %d is too fast", amount);
		return false;
	}

	//EVの充電量がMAXをこえたら
	if ( vehicles[id].cap +  amount > vehicles[id].max_cap ){
		INFO("charge amount %d excess the capacity of EV : (%d -> %d )", amount , vehicles[id].cap, vehicles[id].cap + amount);
		return false;
	}


	vehicles[id].charge(amount);

	info_from_grid.push( energy( vertex_id , amount ) );

	return true;
}

//charge to grid
bool judge::valid_discharge(size_t id, int amount){
	position &pos = vehicles[id].pos;
	if( !pos.on_vertex() ){
		INFO("EV: %d is not on node", pos.now_vertex());
		return false;
	}
	if( amount <= 0 ){
		INFO("charge: %d is not positive", amount);
		return false;
	}
	int vertex_id = pos.now_vertex();
	auto &current_node = g.nodes[vertex_id];
	if ( !current_node.is_grid()  ){
		INFO("node: %d is not nano grid", vertex_id);
		INFO("type: %d", current_node.type);
		return false;
	}

	//放電量の制約を立てておく
	if ( amount > V_Max_EV ){
		INFO("charge: %d is too fast", amount);
		return false;
	}


	// ここから　EV が　ナノグリッドへの充電をする処理を書く部分
	if( amount > vehicles[id].cap ){//容量以上の要求でNGにしておく。
		INFO(" EV energy amount %d lack (%d -> %d) ", amount , vehicles[id].cap , vehicles[id].cap - amount )
		return false;
	}


	vehicles[id].consume(amount);

	info_to_grid.push( energy( vertex_id , amount ) );

	return true;
}


bool judge::valid_end_time(){
	std::map<int,int> delta_grid_total;

	while( !info_day.empty() ){
		energy e = info_day.top();
		info_day.pop();
		delta_grid_total[e.id] += e.amount;
		g.nodes[e.id].pw_actual = e.amount;
	}

	while(!info_to_grid.empty() ){
		energy e = info_to_grid.top();
		info_to_grid.pop();
		delta_grid_total[e.id] += e.amount;
	}
	while(!info_from_grid.empty() ){
		energy e = info_from_grid.top();
		info_from_grid.pop();
		delta_grid_total[e.id] -= e.amount;
	}

	for( auto e:delta_grid_total){
		int vertex_id = e.first;
		int delta = e.second;
		int MinV2 = std::min( V_Max_Grid , g.nodes[ vertex_id ].max_cap - g.nodes[ vertex_id ].cap );
		int MinV3 = - std::min( V_Max_Grid , g.nodes[ vertex_id ].cap );
		g.nodes[ vertex_id ].pw_excess = std::max(0,delta - MinV2);
		g.nodes[ vertex_id ].pw_buy = std::max(0,-delta+MinV3);

		//処理2

		if( delta >= MinV2 ){

			delta = MinV2;
		}


		//処理3		
		if( delta <  MinV3 ){
			int out_charge = -delta + MinV3;
			sum_out_charge += out_charge; 
			delta = MinV3;	
		}else{

		}

		g.nodes[ vertex_id ].cap += delta;

	}

	return true;
}


bool judge::valid_pickup(size_t order_id, size_t vehicle_id){

	if( vehicles[vehicle_id].orders.size() >= N_Max_Trans ){
		std::cerr<<"ERR: Over Pick Up"<<std::endl;
		return false;//最大積載量を超える。
	}

	if( now_orders[order_id].vehicle_id != -1 ) return false;
	if( vehicles[vehicle_id].now_vertex() != now_orders[order_id].from ) return false;

	// process of picking up
	vehicles[vehicle_id].add_order( now_orders[order_id].order_id );	
	now_orders[order_id].vehicle_id = vehicle_id;


	return true;
}



void judge::print_rest_energy(FILE *fp){
	g.print_all_nodes(fp);
	return;
}


void judge::print_Order(FILE *fp){
	fprintf(fp,"%zu\n",num_orders);
	for(size_t i=0;i<now_orders.size();i++){
		if( now_orders[i].end_time == -1 ){
			now_orders[i].print(fp);
		}
	}
	return;
}



#endif
