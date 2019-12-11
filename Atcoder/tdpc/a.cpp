#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)

typedef long long ll;

int N;
vector<int> p(105);

//dp[i][j]: i問目まで解くか解かないか決めたときに、j点が実現されているかどうか
bool dp[105][10005];
int main() {
	cin>>N;
	rep(i,N)cin>>p[i];
	dp[0][0] = true;

	rep(i,N)rep(j,10005){
		if(j+p[i]>=100005)continue;

		if(dp[i][j]){
			dp[i+1][j+p[i]] = true;
			dp[i+1][j] = dp[i][j];
		}
		
	}
	int ans = 0;
	//最後の行（N行目）に答えが乗っているので、それらの数を数える
	rep(j,10005)if(dp[N][j])ans++;
	cout<<ans<<endl;
}