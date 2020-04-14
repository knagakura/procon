#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()		 //sort(all(vi S)) sort(all(string S))
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }


using P = pair<int, int>;		//P.first, P.second
typedef long long ll;
typedef vector<int> vi;
typedef set<int> seti;
typedef vector<string> vs;


const int MOD = 1e9+7;
const int INF = 1e9;
ll ans = 0;
int N;
void dfs(ll x, int a, int b, int c){
	if(x > N){
		return;
	}
	if(a>0&&b>0&&c>0){
		ans++;
	}
	dfs(10*x+3,a+1,b,c);
	dfs(10*x+5,a,b+1,c);
	dfs(10*x+7,a,b,c+1);

}
int main() {
	cin>>N;
	dfs(0,0,0,0);
	cout<<ans<<endl;

}