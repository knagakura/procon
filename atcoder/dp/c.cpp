#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)

typedef long long ll;

const int MOD = 1e9+7;
const int INF = 1e9;

int a[100005][3];
ll dp[100005][3];

int main() {
	int N;
	cin>>N;
	rep(i,N)cin>>a[i][0]>>a[i][1]>>a[i][2];

	//初期条件
	rep(j,3)dp[0][j] = a[0][j];
	
	//dptableの初期値（今回は最大値を取り、0以下にはならないので0で良い）
	rep(i,N)rep(j,3)rep(k,3){
		if(j == k) continue;
		dp[i+1][k] = max(dp[i+1][k],dp[i][j] + a[i+1][k]);
	}
	ll ans = max(dp[N][0],dp[N][1]);
	ans = max(ans,dp[N-1][2]);
	cout<<ans<<endl;
}
