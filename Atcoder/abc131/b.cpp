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
	int N,L;
	cin>>N>>L;
	vector<int> v(N);
	int ans = 0;
	int vmin = INF;
	int j = 0;
	rep(i,N){
		v[i] = L+i+1-1;
		ans+=v[i];
		if(abs(v[i])<abs(vmin)){
			vmin = abs(v[i]);
			j = i;
		}
	}
	ans -= v[j];
	cout<<ans<<endl;
}