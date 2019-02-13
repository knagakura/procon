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
const int inf = 1e9;

int main() {
	int N;
	cin>>N;
	int ans=0;
	ll Nb=1;
	rep1(i,N+1){
		Nb*=i;
		Nb%=MOD;
	}
	cout<<Nb<<endl;
	for (ll i = 1; i*i <= Nb; ++i){
		if(Nb%i==0){
			ans+=2;
			ans%=MOD;
		}
	}
	cout<<ans<<endl;
}