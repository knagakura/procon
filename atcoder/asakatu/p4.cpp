#line 1 "test/ALDS1_11_C.test.cpp"
#define PROBLEM "http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ALDS1_11_C&lang=ja"
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

#line 1 "graph/shortest_path/bfs.hpp"


#line 5 "graph/shortest_path/bfs.hpp"

template<typename T>
class BFS : public Graph<T>{
  public:
    using Graph<T>::N;
    using Graph<T>::G;
    vector<T> d;
    BFS(int _N):Graph<T>::Graph(_N), d(_N,-1){
    }
    vec<T> bfs(int start = 0){
        queue<int> q;
        q.push(start);
        d[start] = 0;
        while(!q.empty()){
            int cur = q.front(); q.pop();
            for(auto nv: G[cur]){
                if(d[nv.to] != -1)continue;
                d[nv.to] = d[cur] + nv.cost;
                q.push(nv.to);
            }
        }
        return d;
    }
};

#line 5 "test/ALDS1_11_C.test.cpp"

int main(){
    int N;
    cin >> N;
    BFS<ll> G(N);
    G.input(N-1, -1, true, false);
    int Q, K;
    cin >> Q >> K;
    K--;
    G.bfs(K);
    rep(i,Q){
        int a,b;
        cin >> a >> b;
        a--;b--;
        cout << G.d[a] + G.d[b] << endl;
    }
}
