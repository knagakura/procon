#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }

typedef long long ll;

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = 1e9;
const ll INFLL = 1e18;
const ll MOD = 1e9+7;

const double PI = acos(-1.0);

const int MAX_V = 150000;
const int MAX_LOG_V = 18;

using Graph = vector<vector<int>>;

Graph G(MAX_V);

//parent[k][v]:vの2^k個上の親
int parent[MAX_LOG_V][MAX_V];
//depth[v]:vの深さ
int depth[MAX_V];

void dfs(int v,int p, int d){
    depth[v] = d;
    parent[0][v] = p;
    for(auto nv:G[v]){
        if(nv == p)continue;
        dfs(nv, v, d+1);
    }
}
void init(int V){
    dfs(0,-1,0);
    for(int k = 0; k + 1 < MAX_LOG_V; ++k){
        for(int v = 0; v < V; ++v){
            if(parent[k][v]<0)parent[k+1][v] = -1;
            else{
                parent[k+1][v] = parent[k][parent[k][v]];
            }
        }
    }
}

int lca(int u, int v){
    //depth[u]<depth[v]を担保（vの方が深い）
    if(depth[u]>depth[v])swap(u, v);
    //uとvの深さが同じになるまで、bを登らせる（depth[u] = depth[v]となる）
    for(int k = 0; k < MAX_LOG_V; ++k){
        if((depth[v]-depth[u]) >> k & 1){
            v = parent[k][v];
        }
    }
    //depthと頂点が一致するということは、rootだということ
    if(u == v)return u;
    //親が同じになるまで同時に登っていく
    for(int k = MAX_LOG_V-1; k >= 0; k--){
        if(parent[k][u] != parent[k][v]){
            u = parent[k][u];
            v = parent[k][v];
        }
    }
    return parent[0][u];
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int V;
    cin>>V;
    rep(i,V){
        int p;
        cin>>p;
        if(p == -1)continue;
        p--;
        G[i].push_back(p);
        G[p].push_back(i);
    }
    /*
    rep(i,V-1){
        int x,y;
        cin>>x>>y;
        x--;y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    */
    init(V);
    int Q;
    cin>>Q;
    rep(i,Q){
        int a,b;
        cin>>a>>b;
        a--;b--;
        int lcaq = lca(a,b);
        //cout<<a<<" "<<b<<" "<<lcaq<<endl;
        if(lcaq == b/*||lcaq == a*/)cout<<"Yes"<<endl;
        else cout<<"No"<<endl;
    }
}
