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
	ll N,T;
	cin>>N>>T;
	vector<ll> A(N+1);
	rep(i,N)cin>>A[i];
	A[N] = -1;
	map<ll, ll> map;
	ll l = A[0];
	ll r = A[N-1];
	rep(i,N){
		if(A[i]<A[i+1])continue;
		//単調増加ではなくなったら（またはi == N-2）
		r = A[i];
		if(r-l > 0){
			map[r-l]++;
			cerr<<l<<" "<<r<<endl;
		}
		l = A[i+1];
	}
	ll ans = 0;
	for(auto x : map){
		cerr<<x.first<<" "<<x.second<<endl;

		ans = x.second;
	}	
	cout<<min(ans,T/2)<<endl;
}