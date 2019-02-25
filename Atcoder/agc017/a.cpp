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
	ll N,P;
	cin>>N>>P;
	vector<ll> A(N);
	int cnt0 = 0,cnt1 = 0;
	rep(i,N){
		cin>>A[i];
		if(A[i]%2==0)cnt0++;
		else cnt1++;
	}
	cout<<cnt0<<endl;
	cout<<cnt1<<endl;
	ll ans = 1;
	if(P==0){
		rep(i,cnt0)ans*=2;
		cout<<ans<<endl;
		int d = 0;
		for (int i = 0; 2*i < cnt1; ++i){
			d += cnt1*(cnt1-1)/2;
		}
		ans*=d;
	}
	cout<<ans<<endl;
}
//偶数を

