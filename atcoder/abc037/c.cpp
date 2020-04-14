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
	int N,K;
	cin>>N>>K;
	vector<ll> a(N);
	ll c = 0;
	rep(i,N){
		cin>>a[i];
		if(i<K)c+=a[i];
	}
	ll ans = c;
	for (int i = 1; i+K-1< N; ++i){
		c = c - a[i-1] + a[i+K-1];
		ans += c;
	}
	cout<<ans<<endl;
}