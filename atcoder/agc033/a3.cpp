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

int main() {
	ll H,W;
	cin>>H>>W;
	vector<string> A(H);
	rep(i,H)cin>>A[i];
	vector<pair<int,P>> v;
	rep(i,H)rep(j,W){
		if(A[i][j] == '#'){
			v.push_back({i+j,{i,j}});
		}
	}
	sort(all(v));
	rep(i,int(v.size())){
		cerr<<v[i].first<<' '<<v[i].second.first<<' '<<v[i].second.second<<endl;
	}

	
	int ans =0;
	cout<<ans<<endl;
}