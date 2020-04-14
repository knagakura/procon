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
ll dp[10005][105];
int main() {
	string K;
	ll N = K.size();
	ll D;
	cin>>K>>D;
	dp[0][0] = 1;
	ll keta = 1;
	for (int i = 0; i < N; ++i){
		int d = N - 1 - i;
		int x = K[d] - '0';
		for (int j = 0; j < D; ++j){
			dp[i+1][(j + (keta * x) % D)%D] += dp[i][j];
			dp[i+1][(j + (keta * x) % D)%D] %= MOD;
		}
		keta *= 10;
		keta %= D;
	}

	for (int i = 0; i < N; ++i){
		rep(j,D){
			cerr<<dp[i][j]<<" ";
		}
		cerr<<endl;
	}
	ll ans = dp[N][0];
	cout<<ans<<endl;

}