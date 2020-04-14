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

//dp table
ll dp[3005][3005];

//input
string S,T;
int N,M;

int main() {
	//input
	cin>>S>>T;
	N = S.size();
	M = T.size();

	//dp
	//初期状態
	dp[0][0] = 0;

	rep(i,N)rep(j,M){
		if(S[i]==T[j]){
			dp[i+1][j+1] = max(dp[i+1][j+1],dp[i][j]+1);
		}
		dp[i+1][j+1] = max(dp[i+1][j+1],dp[i+1][j]);
		dp[i+1][j+1] = max(dp[i+1][j+1],dp[i][j+1]);	
	}

	string ans = "";


	while(N>0 && M>0){
		if(dp[N][M] == dp[N-1][M]){
			N--;
		}
		else if(dp[N][M] == dp[N][M-1]){
			M--;
		}
		else{
			ans = S[N-1] + ans;
			N--; M--;
		}
	}
	cout<<ans<<endl;
}