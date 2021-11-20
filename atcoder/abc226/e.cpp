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
// const ll MOD = 1000000007;
const ll MOD = 998244353;
const long double PI = acos(-1.0);

/*
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const string dir = "DRUL";
*/

struct mint {
    long long x;
    mint(long long _x = 0) : x((_x % MOD + MOD) % MOD) {}
    mint operator-() const { return mint(-x); }
    mint &operator+=(const mint a) {
        if((x += a.x) >= MOD)
            x -= MOD;
        return *this;
    }
    mint &operator-=(const mint a) {
        if((x += MOD - a.x) >= MOD)
            x -= MOD;
        return *this;
    }
    mint &operator*=(const mint a) {
        (x *= a.x) %= MOD;
        return *this;
    }
    mint operator+(const mint a) const {
        mint res(*this);
        return res += a;
    }
    mint operator-(const mint a) const {
        mint res(*this);
        return res -= a;
    }
    mint operator*(const mint a) const {
        mint res(*this);
        return res *= a;
    }
    mint modpow(long long t) const {
        if(!t)
            return 1;
        mint a = modpow(t >> 1);
        a *= a;
        if(t & 1)
            a *= *this;
        return a;
    }
    // for prime MOD
    mint inv() const { return modpow(MOD - 2); }
    mint &operator/=(const mint a) { return (*this) *= a.inv(); }
    mint operator/(const mint a) const {
        mint res(*this);
        return res /= a;
    }
    friend std::ostream &operator<<(std::ostream &os, const mint &a) {
        os << a.x;
        return os;
    }
};

vvec<pair<int, int>> G;
vvec<int> gG;
vector<int> visited;
vector<int> evisited;
map<int, pair<int, int>> mp;
bool ok = true;
void dfs(int cur, int cnt) {
    dump(cur);
    if(cnt == 1) {
        if(G[cur].size() != cnt) {
            return;
        }
    } else if(cnt == 2) {
        if(G[cur].size() < cnt) {
            return;
        }
    }
    visited[cur] = true;
    for(auto [nxt, idx] : G[cur]) {
        dump(cur, nxt);
        dump(gG[cur], gG[nxt]);
        // 辺の処理
        if(evisited[idx]) {
            continue;
            if(mp[idx] != make_pair(cur, nxt)) {
                ok = false;
            }
        } else if(gG[cur].empty()) {
            gG[cur].push_back(nxt);
            mp[idx] = {cur, nxt};
            evisited[idx]++;
        } else if(gG[nxt].empty()) {
            dump(cur, nxt, cur);
            gG[nxt].push_back(cur);
            mp[idx] = {nxt, cur};
            evisited[idx]++;
        } else {
            ok = false;
        }
        //
        if(not visited[nxt]) {
            dfs(nxt, cnt);
        }
    }
}

struct UnionFind{
    int n;
    vector<int> Parent;
    vector<int> sizes;
    UnionFind(int _n):n(_n),Parent(_n),sizes(_n,1){ rep(i,n)Parent[i]=i; }
    //find the root of x
    int root(int x){
        if(x!=Parent[x]){
        Parent[x] = root(Parent[x]);
        }
        return Parent[x];
    }
    //merge x and y
    void unite(int x,int y){
        x = root(x);
        y = root(y);
        if(x == y) return;
        if(sizes[x] < sizes[y]) swap(x, y);
        Parent[y] = x;
        sizes[x] += sizes[y];
    }
    bool same(int x,int y){ return root(x) == root(y); }
    int size(int x){ return sizes[root(x)]; }
    int group_num(){
        set<int> s;
        for(int i = 0; i < n; ++i){
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
    int N, M;
    cin >> N >> M;
    G.resize(N);
    gG.resize(N);
    visited.assign(N, 0);
    evisited.assign(M, 0);
    UnionFind T(N);
    rep(i, M) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back({v, i});
        G[v].push_back({u, i});
        T.unite(v, u);
    }
    if(N != M) {
        cout << 0 << endl;
        return 0;
    }
    mint ans = 0;
    // 葉からやってみる
    rep(i, N) {
        if(visited[i]) {
            continue;
        }
        if(G[i].size() == 1) {
            dump(1, i);
            dfs(i, 1);
        }
    }
    //　単純なサイクルのみの場合
    rep(i, N) {
        if(visited[i]) {
            continue;
        }
        if(G[i].size() == 2) {
            dump(2, i);
            dfs(i, 2);
        }
    }
    // 構成されたグラフを判定する
    dump(G);
    dump(gG);
    dump(mp);
    for(auto g : gG) {
        if(g.size() != 1) {
            cout << 0 << endl;
            return 0;
        }
    }
    //
    dump(ok);
    if(ok) {
        ans = mint(2).modpow(T.group_num());
    }
    cout << ans << endl;
}

/*
頂点を分類する

サイクルを構成する頂点。複数のサイクルに所属してはならない。
サイクル上にあり、他のサイクルとつながるような頂点
サイクル上にはない頂点。
*/