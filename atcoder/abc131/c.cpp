#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()		//sort(all(vi S)) sort(all(string S))
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }

using P = pair<int, int>;		//P.first, P.second
typedef long long ll;
typedef vector<int> vi;
typedef set<int> seti;
typedef vector<string> vs;

const int MOD = 1e9+7;
const int INF = 1e9;

ll Count(ll X, ll Y){
	ll cnt = X/Y;
	return cnt;
}
ll gcd(ll a,ll b){return b==0 ? a : gcd(b,a%b);}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
int main() {
	ll A,B,C,D;
	cin>>A>>B>>C>>D;
	if(C==1||D==1){
		cout<<0<<endl;
		return 0;
	}
	ll A1 = Count(A-1,C)+Count(A-1,D)-Count(A-1,lcm(C,D));
	ll B1 = Count(B,C)+Count(B,D)-Count(B,lcm(C,D));
	ll ans = B-A+1 - (B1-A1);
	cout<<ans<<endl;
}