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

//尺取り法
//しゃくとり法
//https://qiita.com/drken/items/ecd1a472d3a0e7db8dce
int main() {
	ll N,K;
	cin>>N>>K;
	vector<ll> A(N);
	ll sum = 0;
	ll cnt = 0;
	rep(i,N)cin>>A[i];
	int r = 0;
	rep(l,N){
		while(r < N && sum +  A[r] < K){
			sum += A[r];
			r++;
		}
		cnt += r - l;
		cerr<<l<<": "<<"("<<l<<", "<<r<<")"<<endl;
		sum -= A[l];
	}
	ll ans = N*(N+1)/2 - cnt;
	cout<<ans<<endl;
}