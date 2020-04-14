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

int main() {
	int N;
	cin>>N;
	vector<P> xy;
	rep(i,N){
		int x,y;
		cin>>x>>y;
		xy.push_back({x,y});
	}
	sort(all(xy));
	vector<P> A;
	rep(i,N)rep(j,N)if(i<j){
		int x1 = xy[i].first;
		int y1 = xy[i].second;
		int x2 = xy[j].first;
		int y2 = xy[j].second;
		A.push_back({x2-x1, y2-y1});
	}
	sort(all(A));
	/*printpair(xy);
	printpair(A);*/
	int M = A.size();
	int ans = INF;
	rep(i,M){
		int cnt = 0;
		rep(j,M){
			if(A[i] == A[j])cnt++;
		}
		ans = min(ans,N-cnt);
	}
	if(N==1)ans = 1;
	cout<<ans<<endl;
}