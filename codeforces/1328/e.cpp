#line 1 "test/GRL_5_C.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_C&lang=ja"

#line 1 "macro/macros.hpp"



/*
@title Macro
@category template
*/
#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define dump(x) cerr<<#x<<": "<<x<<endl;
#define bit(k) (1LL<<(k))
#define Yes "Yes"
#define No "No"
#define YES "YES"
#define NO "NO"
typedef long long ll;

template< typename T1, typename T2 >
ostream &operator<<(ostream &os, const pair< T1, T2 >& p) {
  os << "{" <<p.first << ", " << p.second << "}";
  return os;
}
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = (ll)1e9;
const ll INFLL = (ll)1e18+1;
const ll MOD = (ll)1e9+7;

const double PI = acos(-1.0);

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const string dir = "DRUL";


#line 1 "tree/lca.cpp"
/*
@title 最小共通祖先/LCA(Lowest Common Acestor)
*/
#line 1 "tree/template.cpp"


#line 1 "graph/template.hpp"


#line 4 "graph/template.hpp"

/*
@title Graph Class
@category template
*/
template<typename T = int>
struct edge{
    int to;
    T cost;
    int id;
    edge(int _to, T _cost = 1, int _id = -1) :to(_to), cost(_cost), id(_id) {}
};

template<class T>
class Graph {
  public:
    int N;
    vvec<edge<T>> G;
    Graph(int _N): N(_N),G(_N){
    }
    void add_Directed_edge(int from, int to, T cost = 1, int id = -1){
        G[from].push_back({to, cost, id});
    }
    void add_edge(int v1, int v2, T cost = 1, int id = -1){
        add_Directed_edge(v1, v2, cost, id);
        add_Directed_edge(v2, v1, cost, id);
    }
    //standard input
    void input(int M, int padding = -1, bool weighted = false, bool directed = false){
        while(M--){
            int a, b;
            cin >> a >> b;
            a += padding;
            b += padding;
            T c = T(1);
            if(weighted)cin >> c;
            if(directed)add_Directed_edge(a,b,c);
            else add_edge(a,b,c);
        }
    }
};

#line 5 "tree/template.cpp"

/*
@title Tree Class
@category template
*/
template<class T>
class Tree {
  public:
    int N;
    vvec<edge<T>> G;
    Tree(int _N): N(_N),G(_N){
    }
    void add_Directed_edge(int from, int to, T cost = 1, int id = -1){
        G[from].push_back({to, cost, id});
    }
    void add_edge(int v1, int v2, T cost = 1, int id = -1){
        add_Directed_edge(v1, v2, cost, id);
        add_Directed_edge(v2, v1, cost, id);
    }
    //standard input
    void input(int M, int padding = -1, bool weighted = false, bool directed = false){
        while(M--){
            int a, b;
            cin >> a >> b;
            a += padding;
            b += padding;
            T c = T(1);
            if(weighted)cin >> c;
            if(directed)add_Directed_edge(a,b,c);
            else add_edge(a,b,c);
        }
    }
};


#line 6 "tree/lca.cpp"

template<typename T>
class LCA :  public Tree<T>{
  public:
    using Tree<T>::N;
    using Tree<T>::G;
    int bitlen = 1;
    vector<int> d; //depth
    vector<vector<int>> anc; // bitlen * N
    LCA(int _N):Tree<T>::Tree(_N){
        init(_N);
    }
    void init(int n){
        while((1 << bitlen) < n){
            bitlen++;
        }
        d.assign(n, 0);
        anc.assign(bitlen, vector<int>(n,-1));
    }
    void dfs(int v = 0, int p = -1){
        anc[0][v] = p;
        for(int i = 0; i+1 < bitlen; ++i){
            anc[i+1][v] = (anc[i][v] >= 0) ? anc[i][anc[i][v]] : -1;
        }
        for(auto ne: G[v]) if(ne.to != p){
            d[ne.to] = d[v]+1;
            dfs(ne.to, v);
        }
    }
    int lca(int u, int v){
        if(d[u] > d[v]) swap(u, v);
        for(int i = 0; i < bitlen;i++){
            if((d[v] - d[u]) & (1<<i)){
                v = anc[i][v];
            }
        }
        if(u == v) return u;
        for(int i = bitlen-1; i >= 0;i--){
            if(anc[i][u] != anc[i][v]){
                u = anc[i][u];
                v = anc[i][v];
            }
        }
        return anc[0][u];
    }
    int calc_dist(int u, int v) {
		int l = lca(u, v);
		return d[u] + d[v] - d[l] * 2;
    }
};
#line 5 "test/GRL_5_C.test.cpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N, Q;
    cin >> N >> Q;
    LCA<long long> G(N);
    G.input(N-1, -1, false, false);
    G.dfs();
    while(Q--){
        int K;
        cin >> K; 
        vec<int> v(K);
        rep(i,K){
            cin >> v[i];
            v[i]--;
        }
        int maxx = -1;
        int mx_idx = -1;
        rep(i,K){
            if(chmax(maxx, G.d[v[i]])){
                mx_idx = v[i];
            }
        }
        bool ok = true;
        rep(i,K){
            int lca = G.lca(mx_idx, v[i]);
            int dist = G.calc_dist(v[i],lca);
            if(dist > 1)ok = false;
        }
        cout << (ok ? "YES" : "NO") << '\n';
    }
}
