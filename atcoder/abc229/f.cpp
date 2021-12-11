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

struct UnionFind {
    int n;
    vector<int> Parent;
    vector<int> sizes;
    UnionFind(int _n) : n(_n), Parent(_n), sizes(_n, 1) {
        rep(i, n) Parent[i] = i;
    }
    // find the root of x
    int root(int x) {
        if(x != Parent[x]) {
            Parent[x] = root(Parent[x]);
        }
        return Parent[x];
    }
    // merge x and y
    void unite(int x, int y) {
        x = root(x);
        y = root(y);
        if(x == y)
            return;
        if(sizes[x] < sizes[y])
            swap(x, y);
        Parent[y] = x;
        sizes[x] += sizes[y];
    }
    bool same(int x, int y) { return root(x) == root(y); }
    int size(int x) { return sizes[root(x)]; }
    int group_num() {
        set<int> s;
        for(int i = 0; i < n; ++i) {
            s.insert(root(i));
        }
        return int(s.size());
    }
};

/*~使い方講座~
まず、main関数内で
    UnionFind uni(N);
と呼び出します（これでUnionFind木のuniちゃんが呼び出されます）。
uniちゃんの中には、NodeがN個あり、
それぞれの親とそれが属する集合の数（size）が定義されています。
    ①二つのNode xとy が同じ集合に属するか確認するとき
    uni.same(x, y);
    とすることで、それらが同じかどうかをtrue/falseで返す
    ②あるNode x が含まれる集合の大きさを知りたいとき
    uni.size(x);
    ③二つのNode xとyを同じ集合に属させたいとき
    uni.unite(x, y);
    ④あるNode xの根を知りたいとき
    uni.root(x);
*/
/*~UnionFind木が出題された問題~
①D-Decayed Bridges
https://beta.atcoder.jp/contests/abc120
UnionFind木は繋がりを断つことはできないが、
構成することはできるので、逆からやるやつ。
②D-Equals
https://beta.atcoder.jp/contests/abc097
swapすればそれらは行き来可能になるので、実質パイプ。
③B-Union Find
https://beta.atcoder.jp/contests/atc001
典型問題。uniteして、繋がってるか聞かれたら答えるだけ。
④B-道路工事
https://beta.atcoder.jp/contests/arc032/
すべての点に対して根を考えることで、
グループが幾つに分かれているかを知ることができる
⑤D-連結
https://beta.atcoder.jp/contests/abc049
二つのUnionFind木を管理して、
同時に繋がっていることを根のPairを持って
mapで管理すると良い
[解説]http://drken1215.hatenablog.com/entry/2019/06/29/182300
⑥D - Friend Suggestions
[問題]https://atcoder.jp/contests/abc157/tasks/abc157_d
[提出]https://atcoder.jp/contests/abc157/submissions/10460043
友達関係のグルーピングに使う
sizeも用いた
⑦E - 1 or 2
[問題]https://atcoder.jp/contests/abc126/tasks/abc126_e
[提出]https://atcoder.jp/contests/abc126/submissions/10649376
集合の数を管理するgroup_numを実装した
*/

int main() {
    int N;
    cin >> N;
    vector<pair<ll, i_i>> edges;
    rep(i, N) {
        ll a;
        cin >> a;
        edges.push_back({a, {0, i + 1}});
    }
    rep(i, N) {
        ll b;
        cin >> b;
        int f = i + 1;
        int t = (i + 1) == N ? 1 : i + 2;
        edges.push_back({b, {f, t}});
    }
    sort(all(edges));
    reverse(all(edges));
    dump(edges);
    UnionFind T(N + 1);
    ll ans = 0;
    vector<pair<ll, i_i>> removed;
    vector<vector<int>> G(N + 1);
    for(auto e : edges) {
        int u = e.second.first;
        int v = e.second.second;
        ll w = e.first;
        if(T.same(u, v)) {
            removed.emplace_back(e);
            ans += w;
            continue;
        }
        dump("unite", e);
        G[u].push_back(v);
        G[v].push_back(u);
        T.unite(u, v);
    }
    queue<int> que;
    vector<int> dis(N + 1, -1);
    {
        que.push(0);
        dis[0] = 0;
        while(!que.empty()) {
            int t = que.front();
            que.pop();
            for(int x : G[t])
                if(dis[x] == -1) {
                    dis[x] = dis[t] + 1;
                    que.push(x);
                }
        }
    }

    dump(dis);
    for(auto e : removed) {
        int u = e.second.first;
        int v = e.second.second;
        ll w = e.first;
        if(dis[u]%2 != dis[v]%2) {
            ans -= w;
        }
    }
    cout << ans << endl;
}
