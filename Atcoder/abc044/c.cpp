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
int N,A;
vector<int> x(N);
int cnt=0;
int k = 0;
ll dfs(int i,int sum){
	if(i==N-1)return cnt;
	if(sum==k*A&&k>0)cnt++;
	cout<<sum<<endl;
	dfs(i+1,sum);
	sum+=x[i];
	k+=1;
	dfs(i+1,sum);
}
int main() {
	cin>>N>>A;
	rep(i,N)cin>>x[i];
	ll ans = dfs(0,0);
	cout<<cnt<<endl;
}