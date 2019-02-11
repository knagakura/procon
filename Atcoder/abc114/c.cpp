#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define all(a) (a).begin(),(a).end()

typedef long long ll;
typedef vector<int> vi;
typedef set<int> seti;
typedef vector<string> vs;

const int MOD = 1e9 + 7;
const int inf = 1e8;
ll N;
int ans = 0;
void dfs(ll x,int a,int b,int c){
	if(x>N) return;
	if(a&b&c)ans++;
	dfs(10*x+3,1,b,c);
	dfs(10*x+5,a,1,c);
	dfs(10*x+7,a,b,1);
}
int main() {
	cin>>N;
	dfs(0,0,0,0);
	cout<<ans<<endl;
}