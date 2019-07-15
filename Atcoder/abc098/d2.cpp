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
	int N;
	cin>>N;
	vector<ll> A(N);
	rep(i,N)cin>>A[i];
	vector<ll> sum(N+1),xorsum(N+1);
	sum[0] = xorsum[0] = 0;
	rep(i,N){
		sum[i+1] = sum[i] + A[i];
		xorsum[i+1] = xorsum[i] ^ A[i];
	}
	ll ans = 0;
	for (int l = 1; l < N+1; ++l){
		ll ok  = l, ng = N+1;
		// (l,ok)は条件を満たし、(l,ng)は条件を満たさない。
		// okとngの距離を縮めていくことで境界値r0を求める
		while(ng - ok > 1){
			ll mid = (ok + ng) / 2;
			if(sum[mid] - sum[l - 1] == (xorsum[mid] ^ xorsum[l-1])){
				ok = mid;
			}
			else{
				ng = mid;
			}
		}
		//最終的なokが境界値r0になる
		ans += ok - l + 1;
	}
	cout<<ans<<endl;
}