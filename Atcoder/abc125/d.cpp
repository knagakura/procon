#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()		//sort(all(vi S)) sort(all(string S))
#define push_back pb
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }

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
	int cntminus = 0;
	ll ans = 0;
	ll minabsA = INF;
	rep(i,N){
		cin>>A[i];
		ans +=abs(A[i]);
		minabsA = min(minabsA, abs(A[i]));
		if(A[i]<0)cntminus++;
		//cout<<ans<<endl;
	}
	//print(A);
	cout<<cntminus<<endl;
	cout<<minabsA<<endl;
	if(cntminus%2 == 1){
		ans -= 2*minabsA;
	}
	cout<<ans<<endl;
}