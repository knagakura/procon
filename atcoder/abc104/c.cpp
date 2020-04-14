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
	int D,G;
	cin>>D>>G;
	vector<int> p(D),c(D);
	rep(i,D)cin>>p[i]>>c[i];
	ll ans = INF;
	// 全探索 --- bit は {0, 1, ..., n-1} の 2^n 通りの部分集合全体を動きます。
	for (int bit = 0; bit < (1<<D); ++bit){
		/* bit で表される集合の処理を書く */
		ll sum = 0;
		ll cnt = 0;
		for (int i = 0; i < D; ++i){
			//100*(i+1)点問題をすべて解くことになっているならば
			if(bit & (1<<i)){
				sum += c[i] + 100*(i+1)*p[i];
				cnt += p[i];
			}
		}
		if(sum >=G){
			ans = min(ans, cnt);
		}
		else{
			for (int i = D-1; i >= 0; --i){
				if(bit & (1<<i))continue;
				for (int j = 0; j < p[i]; ++j){
					if(sum >= G)break;
					sum += 100*(i+1);
					cnt++;
				}
			}
			ans = min(ans, cnt);
		}
	}
	cout<<ans<<endl;
}