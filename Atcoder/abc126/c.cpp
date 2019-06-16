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
	double N,K;
	cin>>N>>K;
	double ans = 0;
	cerr<<1.0/N<<endl;
	rep1(i,N+1){
		int x = int(log2f(K/double(i)))+1;
		if(log2f(K/double(i)) == int(log2f(K/double(i)))){
			x--;
		}
		if(i>=K){
			ans+=1.0/N;
			continue;
		}
		ans += 1.0/N * double(pow(0.5,x));
		cerr<<i<<": "<<x<<endl;
	}
	//cout<<ans<<endl;
	printf("%.12lf\n", ans);
}