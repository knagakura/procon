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
	int N,Q;
	cin>>N>>Q;
	vector<int> ans(N+1);
	rep(i,Q){
		int l,r;
		cin>>l>>r;
		l--;r--;
		ans[l] += 1;
		ans[r+1] -= 1;
	}
	rep1(i,N){
		ans[i] = ans[i-1] + ans[i];
	}
	print(ans);
	rep(i,N){
		cout<<ans[i]%2;
	}
	cout<<endl;
}