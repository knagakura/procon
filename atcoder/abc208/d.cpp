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

ll d[400][400][400];

template<class T> class Dijkstra {
public:
    int N;
    T inf;
    vvec<T> cost;
    vector<vector<pair<T, int>>> edge;
 
    Dijkstra(const int N, T inf) : N(N), inf(inf),cost(N,vec<T>(N,inf)), edge(N) {
    }
 
    void make_edge(int from, int to, T w) {
        edge[from].push_back({ w,to });
    }
 
    void solve(int start) {
        rep(i,N)rep(k,N) cost[i][k] = inf;
 
        priority_queue<
        pair<pair<T, int>,int>, 
        vector<pair<pair<T, int>,int>>,
        greater<pair<pair<T, int>,int>>
        > pq;
        for(auto &u: edge[start]){
            rep(k,N){
                cost[u.second][k] = u.first;
            }
            pq.push({{u.first, u.second}, u.second});
        }
 
        while (!pq.empty()) {
            T v = pq.top().first.first;
            int from = pq.top().first.second;
            int maxx = pq.top().second;
            pq.pop();
            for (auto u : edge[from]) {
                T w = v + u.first;
                u.
                int to = u.second;
                
                if (w < cost[to][maxx]) {
                    cost[to][maxx] = w;
                    int nmaxx = max(to, maxx);
                    cost[to][nmaxx] = w;
                    pq.push({{ w,to }, nmaxx});
                    pq.push({{ w,to }, maxx});
                }
            }
        }
        return;
    }
};

/*
使い方
1. まずインスタンス生成
重みの型、頂点の数、距離の無限大のINFLL
Dijkstra<ll> d(N, INFLL);

2. 辺を貼る
iからjに重みwの辺を貼る場合
d.make_edge(i,j,w);

3. 頂点sから解く
d.solve(s);

4. sからgの距離
d.cost[g]

GigaCode2019 E - 車の乗り継ぎ
https://atcoder.jp/contests/gigacode-2019/submissions/8651446

*/
int main() {
    int N, M;
    cin >> N >> M;
    rep(i,N)rep(j,N)rep(k,N)d[i][j][k] = 0;
    map<pair<int,int>, int> mp;
    Dijkstra<ll> G(N, INFLL);
    rep(i,M){
        int a, b;
        cin >> a >> b;
        a--, b--;
        ll C;
        cin >> C;
        G.make_edge(a, b, C);
        mp[{a, b}] = C;
    }
    rep(i,N){
        G.solve(i);
        rep(j,N)rep(k,N){
            d[i][j][k] = G.cost[j][k] == INFLL ? 0 : G.cost[j][k];
        }
    }
    ll ans = 0;
    rep(i,N)rep(j,N)rep(k,N){
            ans += d[i][j][k];
    }
    rep(i,N)rep(j,N)rep(k,N){
        if(d[i][j][k] == 0)continue;
        dump(i+1, j+1, k+1, d[i][j][k]);
    }
    cout << ans << endl;
    for(int i = 0; i < N; i++){
        cout << i << endl;
    }
}
