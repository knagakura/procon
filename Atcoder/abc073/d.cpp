#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()		//sort(all(vi S)) sort(all(string S))
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }

using P = pair<int, int>;		//P.first, P.second
typedef long long ll;
typedef vector<int> vi;
typedef set<int> seti;
typedef vector<string> vs;

const int MOD = 1e9+7;
const int INF = 1e9;

int dist[216][216];
int main() {
	int N,M,R;
	cin>>N>>M>>R;
	vector<int> r(R);
	rep(i,R){
		cin>>r[i];
		r[i]--;
	}
	rep(i,N)rep(j,N)dist[i][j] = INF;
	rep(i,M){
		int a,b,c;
		cin>>a>>b>>c;
		a--;b--;
		dist[a][b] = dist[b][a] = c;
	}
	rep(k,N)rep(i,N)rep(j,N){
		dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
	}
	ll ans = INF;
	sort(all(r));
	do{
		ll tmp = 0;
		for (int i = 0; i < R-1; ++i){
			tmp += dist[r[i]][r[i+1]];
		}
		ans = min(ans, tmp);
		print(r);
	}while(next_permutation(all(r)));
	cout<<ans<<endl;
}