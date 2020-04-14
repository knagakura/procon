#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define all(a) (a).begin(),(a).end()

typedef vector<int> vi;

int main() {
	int N,M,Dsum=0;
	cin >> N>>M;
	vector<int> X(M),D(M-1);
	rep(i,M)cin>>X[i];
	sort(all(X));
	rep(i,M-1){
		D[i] = X[i+1] - X[i];
		Dsum += D[i];
	}
	sort(all(D));
	if(N<M){
		rep(i,N-1){
			Dsum-=D[M-2-i];
		}
	}
	else Dsum = 0;
	cout << Dsum << endl;
}