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

int N;
int dp[105][10][10][10];

const int A = 0, G = 1, C = 2, T = 3;

int main() {
	cin>>N;
	//初期条件
	dp[0][T][T][T] = 1;
	//文字列Sのイメージ
	// ... T T T A;
	// ... i j k next
	rep(len,N){
		//後ろから3文字目
		rep(i,4){
			//後ろから2文字目
			rep(j,4){
				//後ろから1文字目
				rep(k,4){
					//前の状態で0だったらもうすでにダメだった配列なので抜ける
					if(dp[len][i][j][k] == 0)continue;
					//次の文字を考えたときに
					rep(next,4){
						//次に加える文字がnextのときダメな条件5個を列挙
						if(j == A && k == G && next == C)continue;
						if(j == A && k == C && next == G)continue;
						if(j == G && k == A && next == C)continue;
						if(i == A && k == G && next == C)continue;
						if(i == A && j == G && next == C)continue;

						dp[len+1][j][k][next] += dp[len][i][j][k];
						dp[len+1][j][k][next] %=MOD;
					}
				}
			}
		}
	}
	int ans =0;
	rep(i,4)rep(j,4)rep(k,4){
		ans += dp[N][i][j][k];
		ans %= MOD;
	}
	cout<<ans<<endl;
}