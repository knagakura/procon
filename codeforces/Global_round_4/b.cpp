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
	string S;
	cin>>S;
	int N = S.size();
	ll ans = 0;
	vector<ll> l(N),r(N);
	int cl = 0,cr = 0;
	bool renzoku = false;
	for (int i = 0; i < N; ++i){
		if(S[i] == 'v'){
			if(renzoku){
				cl++;
			}
			renzoku = true;
		}
		else{
			renzoku = false;
		}
		l[i] = cl;
	}
	renzoku = false;
	for (int i = N-1; i >= 0; --i){
		if(S[i] == 'v'){
			if(renzoku){
				cr++;
			}
			renzoku = true;
		}
		else{
			renzoku = false;
		}
		r[i] = cr;
	}
	rep(i,N){
		if(S[i] == 'o'){
			ans += l[i] * r[i];
		}
	}
	cout<<ans<<endl;
}