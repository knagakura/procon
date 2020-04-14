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
	ll N;
	cin>>N;
	ll l = N % 11;
	ll ans;
	if (l==0)ans = N/11 * 2;
	else if(l<=6) ans = N/11 * 2 + 1;
	else ans = N/11 * 2 + 2;
	cout<<ans<<endl;
}