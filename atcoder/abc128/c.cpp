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

int G[15][15];
int main() {
	int N,M;
	cin>>N>>M;
	rep(i,M){
		int k;cin>>k;
		rep(j,k){
			int s;
			cin>>s;
			s--;
			G[s][i] = 1;
		}
	}
	vector<int> p(M);
	rep(i,M)cin>>p[i];

	int ans = 0;
	for (int bit = 0; bit < (1 << N); ++bit) {
		cerr<<bitset<10>(bit)<<endl;
		vector<int> q(M,0);
		for (int i = 0; i < N; ++i) {
			// i個目のスイッチがs付いてるなら
			if ((bit >> i) & 1) {
				cerr<<"i: "<<i<<endl;
				rep(j,M){
					if(G[i][j] == 1){
						cerr<<"i,j: "<<i<<" "<<M-1-j<<endl;
						q[j]+=1;
						q[j]%=2;
					}
				}
			}
		}
		int cnt = 0;
		print(p);
		print(q);
		rep(j,M){
			if(p[j] == q[j])cnt++;
		}
		cerr<<"cnt: "<<cnt<<endl;
		if(cnt == M)ans++;
	}
	cout<<ans<<endl;
}