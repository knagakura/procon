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

ll dp[100005][15];
int main() {
	string S;
	cin>>S;
	dp[0][0] = 1;
	ll N = S.size();
	ll keta = 1;
	for (int i = 0; i < N; ++i){
		int d = N - 1 - i;
		if(S[d] == '?'){
			rep(j,13)rep(k,10){
				dp[i+1][((k*keta)%13 + j)%13] += dp[i][j];
				dp[i+1][((k*keta)%13 + j)%13] %= MOD;			}
		}
		else{
			int x = int(S[d] - '0');
			rep(j,13){
			dp[i+1][((x * keta) % 13 + j)%13] += dp[i][j];
			dp[i+1][((x * keta) % 13 + j)%13] %= MOD;
			}
		}
		keta *= 10;
		keta %= 13;
	}
	ll ans = dp[N][5];
	cout<<ans<<endl;
}