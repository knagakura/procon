#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define bit(k) (1LL<<(k))
#define SUM(v) accumulate(all(v), 0LL)

typedef pair<int, int> i_i;
typedef pair<ll, ll> l_l;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;
struct fast_ios{ fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; }fast_ios_;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

#define TOSTRING(x) string(#x)
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (T &x : vec) is >> x; return is; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) { os  << "["; for(auto _: v) os << _ << ", "; os << "]"; return os; };
template <typename T> ostream &operator<<(ostream &os, set<T> &st) { os << "("; for(auto _: st) { os << _ << ", "; } os << ")";return os;}
template <typename T> ostream &operator<<(ostream &os, multiset<T> &st) { os << "("; for(auto _: st) { os << _ << ", "; } os << ")";return os;}
template <typename T, typename U> ostream &operator<<(ostream &os, const pair< T, U >& p){os << "{" <<p.first << ", " << p.second << "}";return os; }
template <typename T, typename U> ostream &operator<<(ostream &os, const map<T, U> &mp){ os << "["; for(auto _: mp){ os << _ << ", "; } os << "]"; return os; }

#define DUMPOUT cerr
void dump_func(){ DUMPOUT << endl; }
template <class Head, class... Tail> void dump_func(Head &&head, Tail &&... tail) { DUMPOUT << head; if (sizeof...(Tail) > 0) { DUMPOUT << ", "; } dump_func(std::move(tail)...); }

#ifdef DEBUG
#define dbg(...) { dump_func(__VA_ARGS__) }
#define dump(...) DUMPOUT << string(#__VA_ARGS__) << ": "; dump_func(__VA_ARGS__)
#else
#define dbg(...)
#define dump(...)
#endif

const int INF = (ll)1e9;
const ll INFLL = (ll)1e18+1;
const ll MOD = 1000000007;
// const ll MOD = 998244353;
const long double PI = acos(-1.0);

/*
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const string dir = "DRUL";
*/

struct Edge {
    int to;
};
using Graph = vector<vector<Edge>>;
using P = pair<long, long>;

/* Lowlink: グラフの関節点・橋を列挙する構造体
    作成: O(E+V)
    関節点の集合: vector<int> aps
    橋の集合: vector<P> bridges
*/
struct LowLink {
    const Graph &G;
    vector<int> used, ord, low;
    vector<int> aps;  // articulation points
    vector<P> bridges;

    LowLink(const Graph &G_) : G(G_) {
        used.assign(G.size(), 0);
        ord.assign(G.size(), 0);
        low.assign(G.size(), 0);
        int k = 0;
        for (int i = 0; i < (int)G.size(); i++) {
            if (!used[i]) k = dfs(i, k, -1);
        }
        sort(aps.begin(), aps.end()); // 必要ならソートする
        sort(bridges.begin(), bridges.end()); // 必要ならソートする
    }

    int dfs(int id, int k, int par) { // id:探索中の頂点, k:dfsで何番目に探索するか, par:idの親
        used[id] = true;
        ord[id] = k++;
        low[id] = ord[id];
        bool is_aps = false;
        int count = 0; // 子の数
        for (auto &e : G[id]) {
            if (!used[e.to]) {
                count++;
                k = dfs(e.to, k, id);
                low[id] = min(low[id], low[e.to]);
                if (par != -1 && ord[id] <= low[e.to]) is_aps = true; 
                if (ord[id] < low[e.to]) bridges.emplace_back(min(id, e.to), max(id, e.to)); // 条件を満たすので橋  
            } else if (e.to != par) { // eが後退辺の時
                low[id] = min(low[id], ord[e.to]);
            }
        }
        if (par == -1 && count >= 2) is_aps = true; 
        if (is_aps) aps.push_back(id);
        return k;
    }
};
int main() {
    int N, M;
    cin >> N >> M;

    auto f = [&](ll i, ll j) -> ll{
        return i * N + j;
    };
    auto invf = [&](ll x) -> pair<int, int>{
        return {x / N, x % N};
    };
    ll ans = 0;
    map<ll, vector<ll>> mp;
    rep(i,M){
        int a, b;
        ll c;
        cin >> a >> b >> c;
        a--, b--;
        if(a == b){
            ans += max(0LL, c);
            continue;
        }
        if(a > b){
            swap(a, b);
        }
        mp[f(a, b)].push_back(c);
    }
    dump(mp);
    for(auto &[idx, v]: mp){
        sort(all(v));
        while(v.size() > 1){
            ans += max(0LL, v.back());
            v.pop_back();
        }
    }
    dump(mp);
    dump(ans);
    dump(mp.size());
    vector<pair<ll, pair<int, int>>> vals;
    vector<vector<Edge>> G(N);
    for(auto &[idx, v]: mp){
        auto [a, b] = invf(idx);
        vals.push_back({v[0], {a, b}});
        dump(a, b, v);
        G[a].push_back({b});
        G[b].push_back({a});
    }
    LowLink T(G);
    dump(T.bridges);
    map<pair<int, int>, int> isbridge;
    for(auto p: T.bridges){
        isbridge[p]++;
    }

    int canToru = mp.size() - (N-1);
    sort(all(vals));
    reverse(all(vals));
    dump(vals);
    int sz = vals.size();
    rep(i,sz){
        if(canToru == 0){
            break;
        }
        auto [v, ab] = vals[i];
        if(v > 0 && !isbridge[ab]){
            ans += v;
            canToru--;
        }
    }
    cout << ans << endl;
    // +の上位から

}
