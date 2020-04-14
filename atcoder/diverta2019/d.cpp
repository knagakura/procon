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
	vector<ll> A;
	for (ll i = 1; i*i<= N; ++i){
		if(N%i == 0){
			A.push_back(i);
			A.push_back(N/i);
		}
	}
	ll len = A.size();
	sort(all(A));
	print(A);
	ll ans= 0;
	for (int i = 0; i < len; ++i){
		ll M = A[i]-1;
		if(M!=0&&N%M!=0&&N%M == N/M){
				ans+=M;
		}
	}
	cout<<ans<<endl;
}