#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define all(a) (a).begin(),(a).end()

typedef long long ll;
typedef vector<int> vi;
typedef set<int> seti;
typedef vector<string> vs;

const int MOD = 1e9 + 7;
const int inf = 1e10;

int main() {
	int N,K;
	cin>>N>>K;
	vector<int> h(N);
	rep(i,N)cin>>h[i];
	sort(all(h));
	int ans = inf;
	rep(i,N){
		if(i+K-1<N)ans = min(ans,h[i+K-1]-h[i]);
	}
	cout<<ans<<endl;
}