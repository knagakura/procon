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
	int N;
	cin>>N;
	vector<ll> A(N),ans(N+1);
	rep(i,N)cin>>A[i];

	for (int i = 0; i < N; ++i){
		ll sum=0;
		for (int j = i; j < N; ++j){
			sum+=A[j];
			ans[j-i+1]=max(ans[j-i+1],sum);
		}
	}

	rep1(i,N+1){
		cout<<ans[i]<<endl;
	}
}