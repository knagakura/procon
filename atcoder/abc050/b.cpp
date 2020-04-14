#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()		//sort(all(vi S)) sort(all(string S))

typedef long long ll;
typedef vector<int> vi;
typedef set<int> seti;
typedef vector<string> vs;

const int MOD = 1e9+7;
const int inf = 1e9;

int main() {
	int N,M,Tsum=0;
	cin>>N;
	vector<int> T(N),P(M),X(M);
	rep(i,N){
		cin>>T[i];
		Tsum+=T[i];
	}
	cin>>M;
	rep(i,M){
		cin>>P[i]>>X[i];
		cout<<Tsum-T[P[i]-1]+X[i]<<endl;
	}
}