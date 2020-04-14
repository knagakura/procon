#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()		//sort(all(vi S)) sort(all(string S))
#define push_back pb
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }

using P = pair<int, int>;		//P.first, P.second
typedef long long ll;
typedef vector<int> vi;
typedef set<int> seti;
typedef vector<string> vs;

const int MOD = 1e9+7;
const int INF = 1e9;

int main() {
	int N,D;
	cin>>N>>D;
	vs S(D);
	rep(i,D)cin>>S[i];
	vector<bool> f(N);
	int ans = 0;
	rep(i,D)rep(j,D){
		vector<bool> f(N);
		rep(k,N)f[k] = false;
		if(i<j){
			rep(k,N){
				if(S[i][k] == 'o')f[k] = true;
				if(S[j][k] == 'o')f[k] = true;
			}
			int c = 0;
			rep(k,N){
				if(f[k])c++;
			}
			ans = max(ans,c);
		}
	}
	cout<<ans<<endl;
}