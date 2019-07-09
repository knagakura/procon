#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()		//sort(all(vi S)) sort(all(string S))
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }

using P = pair<int, int>;		//P.first, P.second

typedef long long ll;

const int MOD = 1e9+7;
const int INF = 1e9;

using Graph = vector<vector<int>>;

int main() {
	//頂点数、辺数
	int N,M;
	cin>>N>>M;

	//グラフ（隣接リスト表現）
	Graph G(N);
	rep(i,M){
		int a,b;
		cin>>a>>b;
		a--,b--;
		G[a].push_back(b);
		//無向グラフの場合は以下を追加
		G[b].push_back(a);
	}
	return;
}