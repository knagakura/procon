#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)

typedef long long ll;

vector<vector<pair<int,ll>>> G;
vector<ll> point;
vector<bool> visited;
vector<int> flag;

void dfs(int x, int p, int d){
    if(!visited[x]){
        point[x] = d;
        visited[x] = true;
    }
    else{
        if(flag[x] != -1){
            flag[x] = ((point[x] == d) ? 1:-1);
        }
        return;
    }
    for(auto nx:G[x]){
        if(nx.first == p)continue;
        dfs(nx.first, x, d + nx.second);
    }
}

int main() {
    int N,M;
    cin>>N>>M;
    G.resize(N);
    point.assign(N,0);
    visited.assign(N,false);
    flag.assign(N, 0);
    rep(i,M){
        int L,R,D;
        cin>>L>>R>>D;
        L--;R--;
        G[L].push_back({R,D});
        G[R].push_back({L,-D});
    }
    rep(i,N){
        if(!visited[i]){
            dfs(i,-1,0);
        }
    }
    string ans = "Yes";
    rep(i,N){
        if(flag[i] == -1){
            ans = "No";
        }
    }
    cout<< ans <<endl;
}