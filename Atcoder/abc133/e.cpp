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
	int N,M,K;
	cin>>N>>K;
	M = N-1;
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
	return 0;
}

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

// 深さ優先探索
vector<bool> seen;
void dfs(const Graph &G, int v) {
    seen[v] = true; // v を訪問済にする

    // v から行ける各頂点 next_v について
    for (auto next_v : G[v]) { 
        if (seen[next_v]) continue; // next_v が探索済だったらスルー
        dfs(G, next_v); // 再帰的に探索
    }
}

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
	// 頂点 0 をスタートとした探索
    seen.assign(N, false); // 全頂点を「未訪問」に初期化
    dfs(G, 0);
	return;
}