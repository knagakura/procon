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
vector<ll> A(10);

int main() {
	ll N;
	cin>>N;
	rep(i,5)cin>>A[i];
	ll ans = 5;
	ll mina = A[0];
	rep(i,5)mina = min(mina,A[i]);
	if(mina == 1)ans+=N-1;
	else ans+= N/mina;
	cout<<ans<<endl;
}