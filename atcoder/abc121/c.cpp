#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)

#define all(a) (a).begin(),(a).end()		//sort(all(vi S)) sort(all(string S))

typedef long long ll;
typedef vector<ll> vi;
typedef set<ll> seti;
typedef vector<string> vs;

const ll MOD = 1e9+7;
const ll INF = 1e9;

int main() {
	ll N,M;
	cin>>N>>M;
	vector<tuple<ll , ll>> AB(N);
	rep(i,N){
		ll A,B;
		cin>>A>>B;
		AB[i]=make_tuple(A,B);
	}
	sort(all(AB));
	//rep(i,N){
		//cout<<get<0>(AB[i])<<get<1>(AB[i])<<endl;
	//}
	ll ans = 0;
	rep(i,N){
		ll Ai = get<0>(AB[i]);
		ll Bi = get<1>(AB[i]);
		if(M==0)break;
		else{
			if(M>=Bi){
				ans+=Ai*Bi;
				M-=Bi;
				}
			else{
				ans+=Ai*min(Bi,M);
				M-=min(Bi,M);
				}
			}
	}

	cout<<ans<<endl;
}