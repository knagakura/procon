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
const int INF = 1e9;

int main() {
	int A,B,K;
	cin>>A>>B>>K;
	vector<bool> f(INF);
	rep(i,K)f[A+i]=true;
	rep(i,K){
		if(B-K+1+i>=0)
		f[B-K+1+i]=true;
	}
	for (int i = A; i <= B; ++i){
		if(f[i])cout<<i<<endl;
	}
}