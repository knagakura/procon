#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()        //sort(all(vi S)) sort(all(string S))
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }

using P = pair<int, int>;        //P.first, P.second
typedef long long ll;
typedef vector<int> vi;
typedef set<int> seti;
typedef vector<string> vs;

const int MOD = 1e9+7;
const int INF = 1e9;

// グラフ
using Edge = pair<int,long long>; // {辺の行き先, 重み}
using Graph = vector<vector<Edge> >; // グラフ

// 使われうる辺集合
set<pair<int,int> > use;

// s を始点とする Dijkstra
vector<long long> Dijkstra(const Graph &G, int s) {
    vector<long long> dist((int)G.size(), INF);
    vector<vector<int> > prev((int)G.size()); // prev[v] := v から復元できる辺たち
    dist[s] = 0;
    priority_queue<pair<long long,int>, vector<pair<long long,int> >, greater<pair<long long,int> > > que;
    que.push({0, s});
    while (!que.empty()) {
        auto cur = que.top(); que.pop();
        long long cur_dist = cur.first;
        int v = cur.second;
        if (cur_dist > dist[v]) continue; // 効く枝刈り
        for (auto e : G[v]) {
            if (dist[e.first] > dist[v] + e.second) {
                dist[e.first] = dist[v] + e.second;
                que.push({dist[e.first], e.first});

                // 復元のための
                prev[e.first].clear();
                prev[e.first].push_back(v);
            }
            else if (dist[e.first] == dist[v] + e.second) {
                prev[e.first].push_back(v);
            }
        }
    }

    // 使われうる辺集合
    for (int v = 0; v < (int)G.size(); ++v) {
        for (auto u : prev[v]) {
            use.insert(make_pair(min(u, v), max(u, v)));
        }
    }
    return dist;
}

int main() {
    int N, M; cin >> N >> M;
    Graph G(N);
    for (int i = 0; i < M; ++i) {
        int a, b;
        cin >> a >> b;
        --a, --b;
        G[a].push_back(Edge(b, 1));
    }
    int S,T;cin>>S>>T;S--;T--;
    auto x = Dijkstra(G,S);
    print(x);
    ll ans;
    if(x[T]%3 == 0){
        ans = x[T]/3;
        cout<<ans<<endl;
        return 0;
    }
    if(x[T] == INF){
        cout<<-1<<endl;
        return 0;
    }
/*  for (int v = 0; v < N; ++v) Dijkstra(G, v);
    cout << M - (int)use.size() << endl;
*/
    cout<<ans<<endl;
}