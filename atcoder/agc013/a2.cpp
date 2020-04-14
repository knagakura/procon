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
	int ans = 1;
	int now = 0;
	rep(i,N-1){
		if(now==0){
			if(A[i]<A[i+1])now = 1;
			else if(A[i]>A[i+1])now = 2;
		}
		else if(now == 1 && A[i]>A[i+1]){
			now = 0;
			ans++;
		}
		else if(now == 2 && A[i]<A[i+1]){
			now = 0;
			ans++;
		}
	}
	cout<<ans<<endl;
}