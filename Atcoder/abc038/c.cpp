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
	vector<ll> a(N);
	rep(i,N)cin>>a[i];
	ll ans = 0;
	ll cnt = 1;
	rep(i,N-1){
		if(a[i]<a[i+1])cnt++;
		else{
			ans += cnt+cnt*(cnt-1)/2;
			cnt = 1;
			}
	}
	ans+=cnt+cnt*(cnt-1)/2;
	cout<<ans<<endl;
}