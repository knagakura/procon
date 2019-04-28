#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()		//sort(all(vi S)) sort(all(string S))
#define push_back pb
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }

using P = pair<int, int>;		//P.first, P.second
typedef long long ll;
typedef vector<int> vi;
typedef set<int> seti;
typedef vector<string> vs;

const int MOD = 1e9+7;
const int INF = 1e9;
ll dp[100005][2];
int main() {
	int N;
	cin>>N;
	vector<ll> A(N);
	rep(i,N)cin>>A[i];
	dp[0][0] = 0;
	dp[0][1] = -INF;

	rep(i,N){
		dp[i+1][0] = max(dp[i][0] + A[i], dp[i][1] - A[i]);
		dp[i+1][1] = max(dp[i][0] - A[i], dp[i][1] + A[i]);
	}
	ll ans = dp[N][0]; 
	cout<<ans<<endl;
}