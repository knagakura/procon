#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)

typedef long long ll;
typedef vector<string> vs;

const int MOD = 1e9+7;

ll dp[1005][1005];

int main() {
	int H,W;
	cin>>H>>W;
	vs A(H);
	rep(i,H)cin>>A[i];
	dp[0][0] = 1;
	rep(i,H)rep(j,W){
		dp[i][j] %=MOD;
		if(A[i][j] == '.'){
			dp[i+1][j] += dp[i][j];
			dp[i][j+1] += dp[i][j];
		}
	}
	cout<<dp[H-1][W-1]<<endl;
}