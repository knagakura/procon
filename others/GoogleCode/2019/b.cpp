#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()		//sort(all(vi S)) sort(all(string S))

typedef long long ll;
typedef vector<int> vi;
typedef set<int> seti;
typedef vector<string> vs;

const int MOD = 1e9+7;
const int INF = 1e9;
int T;
int R,C;
int a = -1,b = -1;
vector<string> Table(255);
int Cost[255][255];
int main() {
		cin>>T;
	rep1(t,T+1){
		cin>>R>>C;
		rep(i,R)cin>>Table[i];

		rep(i,R)rep(j,C)Cost[i][j] = INF;

		rep(X,R)rep(Y,C){
			if(Table[X][Y] == '1'){
				rep(i,R)rep(j,C) Cost[i][j] = min(Cost[i][j], abs(X-i) + abs(Y-j));
			}
		}

		//ある最大値から見て、他の最大値の距離がすべてその最大値より小さいなら
		//その最大値を更新する価値があることなる
		//むしろ、他の最大値の距離が小さくならないなら、変えても変えても更新する価値がないということになるので
		//答えは元の最大値になる

		//まず最大値を求める
		int Costmax = -1;
		rep(i,R)rep(j,C){
			Costmax = max(Costmax,Cost[i][j]);
		}
		//最大値の数を数える
		int Maxcnt = 0;
		rep(i,R)rep(j,C){
			if(Cost[i][j]==Costmax)Maxcnt++;
		}
		vector<ll> ans;
		rep(X,R)rep(Y,C){
			//ある最大値のところにきたら
			if(Cost[X][Y] == Costmax){
				int cnt =0;
				rep(i,R)rep(j,C){
					//そこからの他の最大値までの距離を計算し
					if(Cost[i][j] == Costmax){
						if(abs(X-i)+abs(Y-j)<Costmax){
							cnt++;
						}
					}
				}
				//すべてにおいて近くなるのだとしたら
				if(cnt == Maxcnt){
					a = X,b = Y;
					X = R;Y = C;//break次のループにはいかないよ
				}
			}
		}
		//aとbが更新されているのだとしたら
		//最大値を出力して終わり
		if(!(a==-1&&b==-1)){
		//その値を更新して（aとbにメモしといた）
		Table[a][b] = '1';
		rep(X,R)rep(Y,C){
			if(Table[X][Y] == '1'){
				rep(i,R)rep(j,C) Cost[i][j] = min(Cost[i][j], abs(X-i) + abs(Y-j));
			}
		}
		//別の最大値を出力すれば良い
		Costmax = -1;
		rep(i,R)rep(j,C){
			Costmax = max(Costmax,Cost[i][j]);
			}
		}
		cout<<"Case #"<<t<<": "<<Costmax<<endl;
	}
}