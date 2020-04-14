#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)

//入力に必要
int N,M;
int a[50],b[50];
//辺
bool graph[50][50];
//頂点
bool visited[50];

//今いる頂点 v
void dfs(int v){
	visited[v] = true;
	//次の頂点
	rep(v2,N){
		//繋がっていなかったら終わりにする
		if (graph[v][v2] == false) continue;
		//すでに訪れていたら終わりにする（終わりにならないので）
		if (visited[v2] == true) continue;
		dfs(v2);
	}
}

int main() {
	//N頂点, M辺
	cin>>N>>M;
	rep(i,M){
		cin>>a[i]>>b[i];
		//0indexの関係で
		a[i]--;b[i]--;
		//graph行列（繋がっているのでTrue）
		graph[a[i]][b[i]] = graph[b[i]][a[i]] = true;

	}
	//通ったかどうかをfalseで初期化
	rep(i,M) visited[i] = false;

	int ans = 0;
	//ある辺を除いたときに連結かどうか判定
	rep(i,M){
		//除いてみる
		graph[a[i]][b[i]] = graph[b[i]][a[i]] = false;
		//頂点の訪れを初期化
		rep(j,N) visited[j] = false;

		//頂点0からスタート
		dfs(0);

		bool bridge = false;
		//もし一つでも訪れていない頂点があるなら
		//橋だったということ
		rep(j,N) if(visited[j] == false) bridge = true;
		if(bridge)ans++;

		//辺を復活させておく
		graph[a[i]][b[i]] = graph[b[i]][a[i]] = true;
	}
	cout<<ans<<endl;
}