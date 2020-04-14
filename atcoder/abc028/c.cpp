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
	vector<int> v(5);
	rep(i,5){
		cin>>v[i];
	}
	print(v);
	vector<int> ans;
	std::map<ll, ll> map;
	int N = 5;
	for (int i = 0; i < N; ++i){
		for (int j = i+1; j < N; ++j){
			for (int k = j+1; k < N; ++k){
				if(map[v[i]+v[j]+v[k]])continue;
				ans.push_back(v[i]+v[j]+v[k]);
				map[v[i]+v[j]+v[k]]++;
			}
		}
	}
	sort(all(ans));
	print(ans);

	cout<<ans[int(ans.size())-3]<<endl;
}