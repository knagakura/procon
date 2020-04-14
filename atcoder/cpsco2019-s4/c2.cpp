#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define all(a) (a).begin(),(a).end()

typedef long long ll;

int main() {
	ll N,D;
	cin>>N>>D;
	vector<ll> R(N);
	rep(i,N)cin>>R[i];
	sort(all(R));
	ll ans = 0;
/*	rep(i,N-2){
		ll r = upper_bound(all(R), R[i] + D) - R.begin()-1;
		if(r-i>=2)ans += (r-i)*(r-i-1)/2;
	}*/
	ll r = 0;
	rep(i,N){
		cerr<<"i: "<<i<<endl;
		while(R[r+1]<=R[i]+D && r+1<N){
			r++;
			cerr<<"\t"<<"r: "<<r<<endl;
		}
		ll len = r - i;
		cerr<<"\t"<<"len: "<<len<<endl;
		if(len>1)
		ans += len*(len-1)/2;
	}
	cout<<ans<<endl;
}