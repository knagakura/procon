#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ul;
typedef unsigned int ui;
const ll mod = 1000000007;
typedef double ld;
typedef complex<ld> Point;
const ll INF = mod * mod;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
const ld eps = 1e-8;
const ld pi = acos(-1.0);
typedef pair<ld, ld> LDP;
typedef pair<ll, ll> LP;
#define fr first
#define sc second

void solve() {
	int n, d; cin >> n >> d;
	vector<int> r(n);
	rep(i, n)cin >> r[i];
	sort(r.begin(), r.end());
	int ri = 0;
	ll ans = 0;
	rep(i, n) {
		cerr<<"i: "<<i<<endl;
		while (ri + 1< n&&r[ri + 1] <= r[i] + d){
			ri++;
			cerr<<"ri: "<<ri<<endl;
		}
		ll len = ri - i;
		cerr<<len<<endl;
		cerr<<endl;
		ans += len * (len - 1) / 2;
	}
	cout << ans << endl;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	solve();
	//stop
	return 0;
}
