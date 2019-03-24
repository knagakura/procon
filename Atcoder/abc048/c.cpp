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
	ll x;
	cin>>N>>x;
	vector<ll> a(N);
	rep(i,N){
		cin>>a[i];
	}
	ll ans = 0;
	if(a[0]>x){
		ans+=a[0]-x;
		a[0] = x;
	}
	for (int i = 0; i+1 <= N-1; ++i){
		if(a[i]+a[i+1]>x){
			ans+=a[i]+a[i+1]-x;
			a[i+1]-=a[i]+a[i+1]-x;
		}
	}
	//rep(i,N)cout<<a[i]<<endl;
	cout<<ans<<endl;
}