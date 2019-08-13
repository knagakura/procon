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

int main() {
	ll S;
	cin>>S;
	if(S == 1e18){
		cout<<0<<" "<<0<<" "<<1000000000<<" "<<0<<" "<<0<<" "<<1000000000<<endl;
		return 0;
	}
	ll a,b,c,d;
	a = 1e9;
	b = 1;
	d = S / a + 1;
	c = a - S % a;
	cerr<<"ad-bc = "<<(a * d - b * c)<<endl;
	cout<<0<<" "<<0<<" "<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
}