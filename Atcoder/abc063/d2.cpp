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

ll N,A,B;
vector<ll> h(1e5 + 1);
bool check(ll t){
	ll cnt = 0;
	rep(i,N){
		if(h[i] > B*t){
			if((h[i]-B*t)%(A-B)==0){
				cnt += (h[i]-B*t)/(A-B);
			}
			else{
				cnt += (h[i]-B*t)/(A-B) + 1;
			}
		}
	}
	return cnt <= t;
}
int main() {
	cin>>N>>A>>B;
	rep(i,N)cin>>h[i];
	ll ng = 0, ok = 1e9+1;
	ll mid;
	while(1){
		if(ok - ng == 1){
			mid = ok;
			break;
		}
		mid = (ng + ok)/2;
		if(check(mid)){
			ok = mid;
		}
		else{
			ng = mid;
		}
	}
	cout<<mid<<endl;
}