#include <bits/stdc++.h>
using namespace std;

#define rep(i,N) for(int i=0;i<int(N);++i)

typedef vector<int> vi;

int main() {
	int ans=0;
	int N,H,W;
	cin >> N>>H>>W;
	vector<int> A(N),B(N);
	rep(i,N){
		cin>>A[i]>>B[i];
		if(A[i]>=H and B[i]>=W)ans++;
	}
	cout << ans << endl;
}