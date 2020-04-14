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
	vector<ll> A(N+1);
	vector<ll> B(N);
	rep(i,N+1){
		cin>>A[i];
	}
	rep(i,N)cin>>B[i];
	print(A);
	print(B);
	ll ans = 0;
	rep(i,N){
		if(A[i]>=B[i]){
			A[i] -= B[i];
			ans += B[i];
		}
		else{
			ans+= A[i];
			A[i] = 0;
			B[i] -= A[i];
			if(A[i+1]>=B[i]){
				A[i+1] -= B[i];
				ans += B[i];
			}
			else{
				ans += A[i+1];
				A[i+1] = 0;
				B[i] -= A[i+1];
			}
		}
	}
	print(A);
	print(B);
	cout<<ans<<endl;
}