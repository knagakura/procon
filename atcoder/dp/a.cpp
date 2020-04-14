#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)

typedef long long ll;

const int INF = 1e9;
vector<ll> h(100005,0);
vector<ll> dp(100005,INF);
int main() {
	int N;
	cin>>N;
	rep(i,N)cin>>h[i];
	dp[0] = 0;
	rep(i,N){
		dp[i+1] = min(dp[i+1],dp[i]+abs(h[i+1]-h[i]));
		dp[i+2] = min(dp[i+2],dp[i]+abs(h[i+2]-h[i]));
	}
	cout<<dp[N-1]<<endl;
}