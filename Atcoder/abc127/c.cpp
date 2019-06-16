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
ll L[100005],R[100005];
int main() {
	int N,M;
	cin>>N>>M;
	rep(i,M){
		cin>>L[i]>>R[i];
	}
	int l0 = L[0],r0 = R[0];
	int ln = L[0],rn = R[0];
	int ans = 0;
	rep1(i,M){
		if(l0<=L[i] && L[i]<=r0){
			ln = L[i];
		}
		if(l0<=R[i] && R[i]<=r0){
			rn = R[i];
		}
		if(R[i]<l0||r0<L[i]){
			cout<<ans<<endl;
			return 0;
		}
	l0 = ln;
	r0 = rn;
	}
	cerr<<l0<<" "<<r0<<endl;;
	ans = r0 - l0 + 1;
	cout<<ans<<endl;
}