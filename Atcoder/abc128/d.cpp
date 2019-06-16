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
	int N,A;
	cin>>N>>A;
	vector<ll> V(N);
	rep(i,N)cin>>V[i];
	int ans = -INF;
	rep(i,N)rep(j,N)rep(k,i)rep(l,j){
		priority_queue<ll, vector<ll>, greater<ll>> pq_min_l,pq_min_r;
		int ans_c = 0;
		//if((i+j+k+l<=A)&&(i+j-k-l<=N)&&(i+j<N)){
			rep(a,i){
				ans_c+=V[a];
				pq_min_l.emplace(V[a]);
			}
			//pq_max_l.emplace(V[A[i]]);
			rep(b,j){
				ans_c+=V[N-1-b];
				pq_min_r.emplace(V[N-1-b]);
			}
			//pq_max_r.emplace(V[A[N-1-j]]);
			rep(c,k){
				ans_c-=pq_min_l.top();pq_min_l.pop();
			}
			rep(d,l){
				ans_c-=pq_min_r.top();pq_min_r.pop();
			}
		//}
		ans = max(ans_c,ans);
	}
	cout<<ans<<endl;
}