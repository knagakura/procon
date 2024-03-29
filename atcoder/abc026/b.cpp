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
const float Pi = 3.14159265358979;
int main() {
	int N;
	cin>>N;
	vector<int> R(N);
	rep(i,N)cin>>R[i];
	sort(all(R), greater<int>());
	print(R);
	float ans = 0;
	rep(i,N){
		if(i%2 == 0)ans += R[i]*R[i];
		else ans -= R[i]*R[i];
	}
	ans *= Pi;
	//cout<<ans<<endl;
	printf("%.14f\n", ans);
}