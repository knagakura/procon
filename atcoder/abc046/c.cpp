#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }

typedef long long ll;

int main() {
	int N;
	cin>>N;
	vector<ll> T(N),A(N),S(N);
	rep(i,N)cin>>T[i]>>A[i];
	ll t, a, k;
	rep(i,N-1){
		if(T[i+1]>=T[i])t = 1;
		if(A[i+1]>=A[i])a = 1;
		if(T[i+1]<T[i]){
			if(T[i]%T[i+1] == 0)
				t = T[i]/T[i+1];
			else
				t = T[i]/T[i+1] + 1;
		}
		if(A[i+1]<A[i]){
			if(A[i]%A[i+1] == 0)
				a = A[i]/A[i+1];
			else
				a = A[i]/A[i+1] + 1;
		}
		k = max(t,a);
		T[i+1] *= k;
		A[i+1] *= k;
	}
	ll ans = T[N-1] + A[N-1];
	print(T);print(A);
	cout<<ans<<endl;
}