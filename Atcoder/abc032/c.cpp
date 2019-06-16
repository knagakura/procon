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
	int N,K;
	cin>>N>>K;
	vector<ll> s(N);
	rep(i,N){
		cin>>s[i];
	}
	rep(i,N){
		if(s[i] == 0){
			cout<<N<<endl;
			return 0;
		}
	}
	int ans = 0;
	int r = 0;
	int mul = 1;
	rep(l,N){
		while(r < N && mul * s[r] <= K){
			mul *=  s[r];
			r++;
		}
		ans = max(ans, r-l);
		if(l == r){
			r++;
		}
		else{
			mul /= s[l];
		}
	}
	cout<<ans<<endl;
}