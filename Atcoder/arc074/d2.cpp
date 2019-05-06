#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)

typedef long long ll;

int main() {
	int N;
	cin>>N;
	vector<ll> A(3*N);
	rep(i,3*N)cin>>A[i];

	//最小値がtop,pop;
	priority_queue<ll,vector<ll>, greater<ll>> ql;
	//最大値がtop,pop;
	priority_queue<ll> qr;

	ll suml = 0,sumr = 0;
	rep(i,N){
		suml += A[i];
		ql.push(A[i]);
		sumr += A[2*N+i];
		qr.push(A[2*N+i]);
	}
	//境界を左側i個までとしたときの、左側の和の最大値
	//境界を右側i個としたときの、右側の和の最小値
	vector<ll> L(N+1), R(N+1);
	L[0] = suml;
	R[0] = sumr;
	rep1(i,N+1){
		suml += A[N-1+i];
		ql.push(A[N-1+i]);
		suml -= ql.top();
		L[i] = suml;
		ql.pop();

		sumr += A[2*N-i];
		qr.push(A[2*N-i]);
		sumr -=qr.top();
		R[i] = sumr;
		qr.pop();
	}
	ll ans = L[0] - R[N];
	rep(i,N+1){
		ans = max(ans,L[i] - R[N-i]);
	}
	cout<<ans<<endl;
}