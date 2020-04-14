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
	ll A,B,C;
	cin>>A>>B>>C;
	if(A*B*C%2==0){
		cout<<0<<endl;
		return 0;
	}
	else{
		ll ans=min(A*B,B*C);
		ans=min(ans,C*A);
		cout<<ans<<endl;
		return 0;
	}
}