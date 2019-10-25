#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()		//sort(all(vi S)) sort(all(string S))

typedef long long ll;

int main() {
	int N;
	cin>>N;
	vector<ll> A(N),B(N),C(N);
	rep(i,N)cin>>A[i];
	rep(i,N)cin>>B[i];
	rep(i,N)cin>>C[i];
	sort(all(A));
	sort(all(C));
	ll ans = 0;
	rep(i,N){
		ll a = lower_bound(all(A),B[i]) - A.begin();
		ll c = C.end() - upper_bound(all(C), B[i]);
		ans += a*c;
	}
	cout<<ans<<endl;
}