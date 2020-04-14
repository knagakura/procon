#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()		//sort(all(vi S)) sort(all(string S))
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }

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
	vector<ll> ans1;
	rep(i,X)rep(j,Y){
		ans1.push_back(A[i]+B[j]);
	}
	sort(all(ans1),greater<ll>());

	vector<ll> ans2 = {};
	int N = min(K,ll(ans1.size()));
	rep(i,N){
		ans2.push_back(ans1[i]);
	}
	sort(all(ans2),greater<ll>());


	vector<ll> ans3 = {};
	rep(i,ans2.size())rep(j,Z){
		ans3.push_back(ans2[i]+C[j]);
	}
	sort(all(ans3),greater<ll>());


	rep(i,K){
		cout<<ans3[i]<<endl;
	}
	
	//print(ans1);print(ans2);print(ans3);
}