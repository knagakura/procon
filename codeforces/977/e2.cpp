#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using Graph = vector<vector<int>>;
Graph G;

vector<bool> visited;
vector<int> edges;
void dfs(int cur){
    visited[cur] = true;
    edges.push_back(cur);
    for(auto nv: G[cur]){
        if(visited[nv])continue;
        dfs(nv);
    }
    return;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;
    G.resize(N);
    visited.assign(N,false);
    rep(i,M){
        int a,b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int ans = 0;
    rep(i,N){
        edges.clear();
        if(visited[i])continue;
        dfs(i);
        bool ok = true;
        for(auto v: edges){
            if(G[v].size() == 2)continue;
            ok = false;
        }
        if(ok) ans++;
    }
    cout << ans << endl;
}