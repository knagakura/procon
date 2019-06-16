#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()		//sort(all(vi S)) sort(all(string S))
#define push_back pb
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }

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
	vector<ll> A(N),B(N),C(N);
	rep(i,N)cin>>A[i];
	rep(i,N)cin>>B[i];
	rep(i,N)cin>>C[i];
	sort(all(A));
	sort(all(B));
	sort(all(C));
	ll ans = 0;
	rep(i,N){
		ll a = lower_bound(all(A),B[i]) - A.begin();
		ll c = N - (upper_bound(all(C),B[i])-C.begin());
		ans += a*c;
	}
	cout<<ans<<endl;
}