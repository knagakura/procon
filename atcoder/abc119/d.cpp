#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

typedef long long ll;

const ll INFLL = 1e18;


int main() {
	ll A,B,Q;
	cin>>A>>B>>Q;
	vector<ll> s(A+2),t(B+2);
	s[0] = t[0] = -INFLL;
	s[A+1] = t[B+1] = INFLL;
	rep1(i,A+1)cin>>s[i];
	rep1(i,B+1)cin>>t[i];
	rep(i,Q){
		ll x; cin>>x;
		ll ans =  INFLL;
		int si = lower_bound(all(s), x) - s.begin();
		int ti = lower_bound(all(t), x) - t.begin();
		for(int j = si-1; j <= si; j++){
			for(int k = ti-1; k <= ti; k++){
				ll S = s[j];
				ll T = t[k];
				chmin(ans, abs(S - x) + abs(S - T));
				chmin(ans, abs(T - x) + abs(T - S));
			}
		}
		cout<<ans<<endl;
	}
}