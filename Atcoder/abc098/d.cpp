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
	vector<int> A(N);
	rep(i,N)cin>>A[i];
	int r = 0;
	ll ans = 0;
	int sum = 0;
	rep(l,N){
		while(r < N&& (sum ^ A[r]) == (sum + A[r])){
			sum += A[r];
			r++;
		}
		ans += r - l;
		if(l == r){
			r++;
		}
		else{
			sum -= A[l];
		}
	}	
	cout<<ans<<endl;
}