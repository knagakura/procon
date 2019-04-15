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

//個数と合計値を持つdp table
//x[i-1]までで個数jで合計値がkになる場合の数をメモ
ll dp[55][80][4000];

int main() {
	int N,A;
	cin>>N>>A;
	vector<int> x(N);
	rep(i,N)cin>>x[i];
	//初期値x[-1]までで個数0で合計値が0になる場合の数は1
	dp[0][0][0] = 1;
	rep(i,N){
		rep(j,50){
			rep(k,3025){
				//x[i]を使わない場合
				dp[i+1][j][k] += dp[i][j][k];
				//x[i]を使う場合、個数が1,合計がx[i]増加する
				dp[i+1][j+1][k+x[i]] += dp[i][j][k];
			}
		}
	}
	ll ans = 0;
	rep1(j,55)rep(k,3025){
		if(j*A==k)
		ans += dp[N][j][k];
	}
	cout<<ans<<endl;
}