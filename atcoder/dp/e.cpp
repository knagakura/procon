#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)

typedef long long ll;

const ll INF = 1e9;

const int MAX_N = 105;
const int MAX_V = 1005;

//input
ll N,W;
vector<ll> w(MAX_N),v(MAX_N);

//dp
ll dp[MAX_N][MAX_N*MAX_V];

int main() {
	cin>>N>>W;
	rep(i,N)cin>>w[i]>>v[i];

	//初期値
	rep(i,MAX_N)rep(j,MAX_N*MAX_V){
		dp[i][j] = INF;
	}
	dp[0][0] = 0;

	//rep(i,N)rep(j,MAX_N*MAX_V){
	//	if(j+v[i]<=MAX_N*MAX_V){
	//		dp[i+1][j+v[i]] = min(dp[i+1][j+v[i]], dp[i][j]+w[i]);
	//		dp[i+1][j] 		= min(dp[i+1][j],dp[i][j]);
	//	}
	//}

	rep(i,N)rep(i,MAX_N*MAX_V){
		if(j-v[i]>=0)dp[i+1][j] = min(dp[i+1][j],dp[i][j-v[i]]+w[i]);
		
	}

	ll ans = 0;
	rep(j,MAX_N*MAX_V){
		if(dp[N][j]<=W){
			ans = j;
			cout<<j<<endl;
		}
	}
	cout<<ans<<endl;
}