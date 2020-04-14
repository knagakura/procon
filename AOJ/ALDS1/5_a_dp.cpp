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

int main() {
	int N;
	cin>>N;
	vector<int> A(N);
	rep(i,N)cin>>A[i];
	int dp[N+1][20320];

	rep(i,N){
		rep(j,20320){
			dp[i][j] = -1;
		}
	}
	dp[0][0] = 1;

	rep(i,N){
		rep(j,2030){
			if(dp[i][j] == 1){
				dp[i+1][j+A[i]] = 1;
				dp[i+1][j] = 1;
			}
		}
	}

	int q;cin>>q;
	rep(i,q){
		int m;
		cin>>m;
		if(dp[N][m]){
			cout<<"yes"<<endl;
		}
		else{
			cout<<"no"<<endl;
		}
	}
	return 0;
}