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

ll H,W,N;
bool IsInField(int x, int y){
	if(0<x&&x<H-1&&0<y&&y<W-1){
		return true;
	}
	else{
		return false;
	}
}
int main() {
	cin>>H>>W>>N;
	vector<P> ab;
	rep(i,N){
		int a,b;
		cin>>a>>b;
		ab.push_back({a,b});
	}
	sort(all(ab));
	printpair(ab);
	map<P, ll> map;
	for (int i = 0; i < N; ++i){
		int x = ab[i].first;
		int y = ab[i].second;
		for (int j = 0; j <= 2; ++j){
			for (int k = 0; k <= 2; ++k){
				if(IsInField(x - j,y - k)){
					map[{x - j, y - k}]++;
				}
			}
		}
	}
	vector<ll> ans(10);
	ans[0] = (H-2)*(W-2);
	for(auto x: map){
		ans[x.second]++;
		ans[0]--;
	}
	for (int i = 0; i < 10; ++i){
		cout<<ans[i]<<endl;
	}
}