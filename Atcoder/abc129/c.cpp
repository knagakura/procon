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

ll dp[100005];
int breaked[100005];
int main() {
	ll N,M;
	cin>>N>>M;
	int a;
	rep(i,M){
		cin>>a;
		breaked[a] = 1;
	}
	dp[0] = 1;
	rep(i,N+1){
		if(!(breaked[i+1])){
			if(i-1>=0){
				dp[i+1]+= dp[i]+dp[i-1];
				dp[i+1]%=MOD;
			}
			else{
				dp[i+1]+= dp[i];
				dp[i+1]%=MOD;
			}
		}
/*		if(!(breaked[i+2])){
			if(!(breaked[i+1])){
				dp[i+2]+= dp[i+1];
				dp[i+2]%=MOD;
			}
			if(!(breaked[i])){
				dp[i+2]+= dp[i];
				dp[i+2]%= MOD;
			}
		}*/
	}
	rep(i,N+1){
		cerr<<dp[i]<<" ";
	}
	cerr<<endl;
	ll ans = dp[N]%MOD;
	cout<<ans<<endl;
}