#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }

int gcd(int a,int b){
    if(b == 0) return a;
    gcd(b, a%b);
}

int main() {
	int N;cin>>N;
	vector<int> A(N),L(N),R(N);
	rep(i,N)cin>>A[i];

	L[0] = A[0];
	R[N-1] = A[N-1];

	rep(i,N-1){
		L[i+1] = gcd(L[i],A[i+1]);
	}
	for (int i = N-1; i > 0; i--){
		R[i-1] = gcd(R[i],A[i-1]);
	}
	int ans = 0;
	rep(i,N){
		if(i == 0)ans = max(ans, R[1]);
		else if(i == N-1)ans = max(ans, L[N-2]);
		else ans = max(ans, gcd(L[i-1],R[i+1]));
	}
	cout<<ans<<endl;
}