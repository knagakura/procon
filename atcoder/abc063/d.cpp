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
	ll N,A,B;
	cin>>N>>A>>B;
	vector<ll> h(N);
	rep(i,N)cin>>h[i];
	sort(all(h));
	print(h);
	ll cumsum = 0;
	ll cnt = 0;
	ll ans = 0;
	for (int i = N-1; i >= 0; --i){
		h[i] -= cumsum;
		if(h[i] <=0){
			break;
		}
		if(h[i] % A == 0){
			cnt = h[i]/A;
		}
		else{
			cnt = h[i]/A + 1;
		}
		cumsum += B * cnt;
		ans += cnt;
	}	
	cout<<ans<<endl;
}