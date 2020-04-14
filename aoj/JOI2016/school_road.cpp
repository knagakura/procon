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

int a,b,n,x,y;
bool table[20][20];
int dp[20][20];
int main() {

	while(1){
		cin>>a>>b;
		if(a == 0 && b == 0)break;
		cin>>n;
		rep(i,20)rep(j,20){
			table[i][j] = true;
			dp[i][j] = 0;
		}
		rep(i,n){
			cin>>x>>y;
			x--;y--;
			table[x][y] = false;
		}
		dp[0][0] = 1;
		rep(i,a)rep(j,b){
			if(table[i][j]){
				dp[i+1][j] += dp[i][j];
				dp[i][j+1] += dp[i][j];
			}
		}
		cout<<dp[a-1][b-1]<<endl;
	}
}