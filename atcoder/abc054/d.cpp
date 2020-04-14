#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()		//sort(all(vi S)) sort(all(string S))
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }

using P = pair<int, int>;		//P.first, P.second
typedef long long ll;
typedef vector<int> vi;
typedef set<int> seti;
typedef vector<string> vs;

const int MOD = 1e9+7;
const int INF = 1e9;
ll dp[43][432][432];
int main() {
	ll N,Ma,Mb;
	cin>>N>>Ma>>Mb;
	rep(i,N+2)rep(j,410)rep(k,410){
		dp[i][j][k] = INF;
	}
	dp[0][0][0] = 0;
	rep(i,N){
		ll a,b,c;
		cin>>a>>b>>c;
		rep(j,410)rep(k,410){
		//i番目を選ぶとき
		dp[i+1][j+a][k+b] = min(dp[i+1][j+a][k+b], dp[i][j][k] + c);
		//i番目を選ばないとき
		dp[i+1][j][k] = min(dp[i+1][j][k], dp[i][j][k]);
		}
	}
	ll ans = INF;
	rep1(i,N+1)rep1(j,410)rep1(k,410){
		//j:k = Ma:Mbであるか
		if(j*Mb == k*Ma){
			ans = min(ans, dp[i][j][k]);
		}
	}
	if(ans == INF)ans = -1;
	cout<<ans<<endl;
}