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
	vector<int> t(N);
	rep(i,N)cin>>t[i];
	int ans = INF;
	// 全探索 --- bit は {0, 1, ..., n-1} の 2^n 通りの部分集合全体を動きます。
	for (int bit = 0; bit < (1<<N); ++bit){
		/* bit で表される集合の処理を書く */
		int a1 = 0;
		int a2 = 0;
		for (int i = 0; i < N; ++i){
			if(bit & (1<<i)){
				a1 += t[i];
			}
			else{
				a2 += t[i];
			}
		}
		ans = min(ans, max(a1,a2));
	}
	cout<<ans<<endl;
}