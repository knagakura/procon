#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()		//sort(all(vi S)) sort(all(string S))
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }

using P = pair<int, int>;		//P.first, P.second
typedef long long ll;
typedef vector<int> vi;
typedef set<int> seti;
typedef vector<string> vs;

const int MOD = 1e9+7;
const int INF = 1e9;

int main() {
	ll N;
	cin>>N;
	vector<ll> a(N);
	vector<P> ap;
	rep(i,N){
		cin>>a[i];
		ap.push_back({a[i],i});
	}
	sort(all(ap));
	vector<ll> b(N);
	rep(i,N)b[i] = 0;
	rep(i,N)cerr<<ap[i].first<<" "<<ap[i].second<<endl;
	rep(i,N-1){
		if(ap[i].first==ap[i+1].first){
			b[ap[i+1].second] = b[ap[i].second];
		}
		else if(ap[i].first<ap[i+1].first){
			b[ap[i+1].second] = b[ap[i].second]+1;
		}
	}
	rep(i,N)cout<<b[i]<<endl;
}