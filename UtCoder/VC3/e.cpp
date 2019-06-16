#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()		//sort(all(vi S)) sort(all(string S))
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }

using P = pair<int, int>;		//P.first, P.second
typedef long long ll;
typedef vector<int> vi;
typedef set<int> seti;
typedef vector<string> vs;

const int MOD = 1e9+7;
const int INF = 1e9;
ll dp[500005];
int main() {
	ll N,H,A,B,C,D,E;
	cin>>N>>H>>A>>B>>C>>D>>E;
	dp[0] = 0;
	rep(i,N){
		dp[i+1] = 
		if(H-E>0)
	}
	int ans;
	
	cout<<ans<<endl;
}