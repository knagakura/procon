#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define all(a) (a).begin(),(a).end()

typedef vector<int> vi;

int main() {
	int N,Lsum = 0,Lmax = 0;
	cin >> N;
	vi L(N);
	rep(i,N){
		cin>>L[i];
		Lmax = max(Lmax,L[i]);
		Lsum+=L[i];
	}
	string ans = "No";
	if(Lsum-Lmax > Lmax)ans = "Yes";
	cout << ans << endl;
}