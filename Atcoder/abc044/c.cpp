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

ll N,A;
vector<int> x(55);
ll dp[55][2505][55];
int main() {
	cin>>N>>A;
	rep(i,N)cin>>x[i];
	sort(all(x));

	dp[0][0][0]= 1;

	rep(i,N)rep(j,N*A+1)rep(k,N+1){
		if(j+x[i]<=N*A){
			dp[i+1][j+x[i]][k+1] += dp[i][j][k];
		}
		dp[i+1][j][k] += dp[i][j][k];
	}

	rep(i,N){
		rep(j,N*A+1){
			rep(k,N+1){
				cout<<dp[i][j][k]<<endl;
			}
		}
	}
	int ans = 0;
	rep(j,N*A+1)rep1(k,N+1){
		if(dp[N][j][k] == k*A){
			cout<<dp[N][j][k]<<endl;
			ans += dp[N][j][k];
		}
	}
	cout<<ans<<endl;
}