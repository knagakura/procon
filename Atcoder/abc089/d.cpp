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
int A[324][324];
int H,W,D,Q;
int d[100000];
int main() {
	cin>>H>>W>>D;
	std::map<ll, P> map;
	rep(i,H)rep(j,W){
		cin>>A[i][j];
		map[A[i][j]] = {i,j};
	}
	cin>>Q;
	for (int i = D+1; i <= H*W; ++i){
		d[i] = d[i-D] + abs(map[i].first-map[i-D].first) + abs(map[i].second-map[i-D].second);
	}
	rep(i,Q){
		int L,R,ans = 0;
		cin>>L>>R;
/*		while(L+D<=R){
			ans+= abs(map[L+D].first - map[L].first);
			ans+= abs(map[L+D].second- map[L].second);
			L+=D;
		}*/
		ans = d[R]-d[L];
		cout<<ans<<endl;
	}
	/*rep(i,H*W){
		cerr<<map[i+1].first<<" "<<map[i+1].second<<endl;
	}*/
}