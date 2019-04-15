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
ll X,Y,Z,K;
vector<ll> A(1005),B(1005),C(1005);
int main() {
	cin>>X>>Y>>Z>>K;
	rep(i,X)cin>>A[i];
	rep(i,Y)cin>>B[i];
	rep(i,Z)cin>>C[i];
	sort(all(A),greater<ll>());
	sort(all(B),greater<ll>());
	sort(all(C),greater<ll>());
	//
	vector<ll> ans;
	rep(i,X)rep(j,Y)rep(k,Z){
		ans.push_back(A[i]+B[j]+C[k]);
	}
	sort(all(ans),greater<ll>());
	rep(i,K){
		cout<<ans[i]<<endl;
	}
}