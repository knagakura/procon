#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
using P = pair<int, int>;
typedef long long ll;

int main() {
	ll N,M;
	cin>>N>>M;
	vector<ll> A(N);
	rep(i,N)cin>>A[i];
	sort(all(A));
	vector<P> CB;
	ll b,c;
	rep(i,M){
		cin>>b>>c;
		CB.push_back({c,b});
	}
	sort(all(CB), greater<P>());
	ll now = 0;
	rep(i,M){
		b = CB[i].second;
		c = CB[i].first;
		rep(j,b){
			if(A[now]>c){
				j = b;
				i = M;
			}
			else{
				A[now] = c;
				now++;
			}
		}
	}

	ll ans = 0;
	rep(i,N)ans+=A[i];
	cout<<ans<<endl;
}