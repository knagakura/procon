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
ll a,b;
int main() {
	int N;
	cin>>N;
	vector<P> ab;
	rep(i,N){
		cin>>a>>b;
		a %= b;
		ab.push_back({a,b});
	}
	printpair(ab);
	ll ans = 0;
	for (int i = N-1; i >= 0; --i){
		a = ab[i].first;
		b = ab[i].second;
		a += ans;
		a %= b;
		if(a == 0){
			continue;
		}
		ans += b - a;
	}
	cout<<ans<<endl;
}