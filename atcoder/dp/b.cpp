#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)

typedef long long ll;

const int INF = 1e9;
vector<ll> h(100005,0);
vector<ll> dp(100005,INF);
int main() {
	int N,K;
	cin>>N>>K;
	rep(i,N)cin>>h[i];
	dp[0] = 0;
	rep(i,N)rep1(j,K+1){
		dp[i+j] = min(dp[i+j],dp[i]+abs(h[i+j]-h[i]));
	}
	cout<<dp[N-1]<<endl;
}
