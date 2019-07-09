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
int cnt[3000];
int main() {
	rep(i,3000)cnt[i] = 0;

	ll L,R;
	cin>>L>>R;
	map<int, int> map;
	vector<int> v;
	for (int i = L; i <= R; ++i){
		if(cnt[i%2019]){
			cnt[i%2019]++;
			continue;
		}
		cnt[i%2019]++;
		v.push_back(i%2019);
		if(int(v.size()) == 2019)break;
	}
	int ans = INF;
/*	for(auto x:map){
		int a = x.first;
		for(auto y:map){
			if(x.first == y.first&&x.second<2)continue;
			ans = min(ans, (x.first*y.first)%2019);
		}
	}*/
	rep(i,v.size()){
		rep(j,v.size()){
			if(v[i] == v[j]){
				if(cnt[v[i]]<2)continue;
			}
			ans = min(ans, (v[i]*v[j])%2019);
		}
	}
	cout<<ans<<endl;
}