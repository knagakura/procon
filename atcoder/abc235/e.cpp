#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for(int i = 0; i < int(N); ++i)
#define rep1(i, N) for(int i = 1; i < int(N); ++i)
#define all(a) (a).begin(), (a).end()
#define bit(k) (1LL << (k))
#define SUM(v) accumulate(all(v), 0LL)

typedef pair<int, int> i_i;
typedef pair<ll, ll> l_l;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;
struct fast_ios {
    fast_ios() {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(20);
    };
} fast_ios_;

template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

#define TOSTRING(x) string(#x)
template <typename T> istream &operator>>(istream &is, vector<T> &vec) {
    for(T &x : vec)
        is >> x;
    return is;
}
template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) {
    os << "[";
    for(auto _ : v)
        os << _ << ", ";
    os << "]";
    return os;
};
template <typename T> ostream &operator<<(ostream &os, set<T> &st) {
    os << "(";
    for(auto _ : st) {
        os << _ << ", ";
    }
    os << ")";
    return os;
}
template <typename T> ostream &operator<<(ostream &os, multiset<T> &st) {
    os << "(";
    for(auto _ : st) {
        os << _ << ", ";
    }
    os << ")";
    return os;
}
template <typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
    os << "{" << p.first << ", " << p.second << "}";
    return os;
}
template <typename T, typename U>
ostream &operator<<(ostream &os, const map<T, U> &mp) {
    os << "[";
    for(auto _ : mp) {
        os << _ << ", ";
    }
    os << "]";
    return os;
}

#define DUMPOUT cerr
void dump_func() { DUMPOUT << endl; }
template <class Head, class... Tail>
void dump_func(Head &&head, Tail &&...tail) {
    DUMPOUT << head;
    if(sizeof...(Tail) > 0) {
        DUMPOUT << ", ";
    }
    dump_func(std::move(tail)...);
}

#ifdef DEBUG
#define dbg(...)                                                               \
    { dump_func(__VA_ARGS__) }
#define dump(...)                                                              \
    DUMPOUT << string(#__VA_ARGS__) << ": ";                                   \
    dump_func(__VA_ARGS__)
#else
#define dbg(...)
#define dump(...)
#endif

const int INF = (ll)1e9;
const ll INFLL = (ll)1e18 + 1;
const ll MOD = 1000000007;
// const ll MOD = 998244353;
const long double PI = acos(-1.0);

/*
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const string dir = "DRUL";
*/
struct UnionFind { // The range of node number is u 0 v n-1
    vector<int> rank, parents;
    UnionFind() {}
    UnionFind(int n) { // make n trees.
        rank.resize(n, 0);
        parents.resize(n, 0);
        for(int i = 0; i < n; i++) {
            makeTree(i);
        }
    }
    void makeTree(int x) {
        parents[x] = x; // the parent of x is x
        rank[x] = 0;
    }
    bool isSame(int x, int y) { return findRoot(x) == findRoot(y); }
    void unite(int x, int y) {
        x = findRoot(x);
        y = findRoot(y);
        if(rank[x] > rank[y]) {
            parents[y] = x;
        } else {
            parents[x] = y;
            if(rank[x] == rank[y]) {
                rank[y]++;
            }
        }
    }
    int findRoot(int x) {
        if(x != parents[x])
            parents[x] = findRoot(parents[x]);
        return parents[x];
    }
};
// 辺の定義
struct Edge {
    ll u;
    ll v;
    ll cost;
    int idx;
    bool is_query;
};
bool comp_e(const Edge &e1, const Edge &e2) {
    return e1.cost < e2.cost;
} // 辺を直接比較するための関数
/* Kruskal :クラスカル法で minimum spanning tree を求める構造体
    入力: 辺のvector, 頂点数V
    最小全域木の重みの総和: sum
    計算量: O(|E|log|V|)
*/
struct Kruskal {
    UnionFind uft;
    ll sum; // 最小全域木の重みの総和
    vector<Edge> edges;
    vector<int> ans;
    int V;
    Kruskal(const vector<Edge> &edges_, int V_, int Q) : edges(edges_), V(V_), ans(Q, -1){
        init();
    }
    void init() {
        sort(edges.begin(), edges.end(), comp_e); // 辺の重みでソート
        uft = UnionFind(V);
        sum = 0;
        for(auto e : edges) {
            if(e.is_query) {
                if(!uft.isSame(e.u, e.v)) {
                    ans[e.idx] = 1;
                }
                continue;
            }
            if(!uft.isSame(e.u, e.v)) { // 閉路にならなければ加える
                uft.unite(e.u, e.v);
                sum += e.cost;
            }
        }
    }
};

int main() {
    int N, M, Q;
    cin >> N >> M >> Q;
    vector<Edge> edges;
    rep(i, M) {
        int a, b, c;
        cin >> a >> b >> c;
        a--, b--;
        edges.push_back({a, b, c, -1, false});
    }
    rep(i, Q) {
        int u, v, w;
        cin >> u >> v >> w;
        u--, v--;
        edges.push_back({u, v, w, i, true});
    }
    Kruskal krs(edges, M+Q, Q);
    krs.init();
    for(int a: krs.ans){
        if(a == -1) {
            cout << "No" << endl;
        } else {
            cout << "Yes" << endl;
        }
    }
}
