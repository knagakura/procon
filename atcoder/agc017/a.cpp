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
ll N,P;
vector<int> A(55);
ll dp[55][2];
int main() {
	cin>>N>>P;
	dp[0][0] = 1;
	rep(i,N)cin>>A[i];
	rep(i,N){
		//選ばない場合
		dp[i+1][0] += dp[i][0];
		dp[i+1][1] += dp[i][1];
		//偶数を選ぶ場合
		if(A[i]%2 == 0){
			dp[i+1][0] += dp[i][0];
			dp[i+1][1] += dp[i][1];
		}
		//奇数を選ぶ場合
		else{
			dp[i+1][0] += dp[i][1];
			dp[i+1][1] += dp[i][0];
		}
	}
	ll ans = dp[N][P];
	cout<<ans<<endl;
}