#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define bit(k) (1LL<<(k))
typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = 1e9;
const ll INFLL = 1e18;
const ll MOD = 1e9+7;
const double PI = acos(-1.0);

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

/*------------------------------------/
for library*/
/*------------------------------------*/

int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cout << fixed << setprecision(20);

	ll N,K;
	cin>>N>>K;
	vector<ll> A(N);
	rep(i,N)cin>>A[i];
	ll maxx = 0;
	//bitのk桁目が立っている個数を数える
	//大きい方から決めていくべき
	for(ll k = 43;k>=0;k--){
		if(bit(k)>K)continue;
		int cnt = 0;
		rep(i,N){
			if(A[i]&bit(k))cnt++;
		}
		if(cnt < N - cnt){//0の方が多い
			if((maxx | bit(k) )>K)continue;
			maxx |= (1LL<<k);
		}
	}
	ll ans = 0;
	rep(i,N){
		ans += (ll)(maxx ^ A[i]);
	}
	cout<<ans<<endl;
}