#include <bits/stdc++.h>
#include <atcoder/mincostflow>
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
template <typename T, typename U> ostream &operator<<(ostream &os, const pair< T, U >& p){os << "{" <<p.first << ", " << p.second << "}";return os; }
template <typename T, typename U> ostream &operator<<(ostream &os, const map<T, U> &mp){ os << "["; for(auto _: mp){ os << _ << ", "; } os << "]" << endl; return os; }

#define DUMPOUT cerr
void dump_func(){ DUMPOUT << endl; }
template <class Head, class... Tail> void dump_func(Head &&head, Tail &&... tail) { DUMPOUT << head; if (sizeof...(Tail) > 0) { DUMPOUT << ", "; } dump_func(std::move(tail)...); }

#ifdef DEBUG
#define dbg(...) dump_func(__VA_ARGS__)
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


int main() {
    int N, K;
    cin >> N >> K;
    vvec<ll> A(N, vector<ll>(N, 0LL));
    rep(i,N)cin >> A[i];

    // int sz = N * N + N + N + 2;
    // atcoder::mcf_graph<ll,ll> G(sz);
    // int s = sz - 2;
    // int t = sz - 1;
    // auto f = [&](int i, int j) {
    //     return i * N + j;
    // };
    // auto super_i = [&](int i){
    //     return N * N + i;
    // };
    // auto super_j = [&](int j){
    //     return N * N + N + j;
    // };
    // const ll inf = 1000;
    // //ある行iについて
    // rep(i,N){
    //     int sup = super_i(i);
    //     G.add_edge(s, sup, K, 0);
    //     dump(s, sup);
    //     rep(j,N){
    //         G.add_edge(sup, f(i,j), 1, inf - A[i][j]);
    //         dump(sup, f(i,j));
    //     }
    // }
    // // ある列jについて
    // rep(j,N){
    //     int sup = super_j(j);
    //     G.add_edge(s, sup, K, 0);
    //     dump(s, sup);
    //     rep(i,N){
    //         G.add_edge(sup, f(i,j), 1, inf - A[i][j]);
    //         dump(sup, f(i,j));
    //     }
    // }
    // // マスからtへ
    // rep(i,N)rep(j,N){
    //     G.add_edge(f(i,j), t, 1, 0);
    //     dump(f(i,j), t);
    // }
    // for(int cnt = 1; cnt <= N*N; cnt++){
    //     auto [cap, flow] = G.flow(s, t, cnt);
    //     dump(cnt, cap, flow);
    //     for(auto e: G.edges()){
    //         if(e.flow > 0 && e.cost > 0){
    //             dump(e.from, e.to, e.flow, inf - e.cost);
    //         }
    //     }
    //     cerr << endl;
    // }
    auto f = [&](int i, int j) -> int{
        return i * N + j;
    };
    auto sup_i = [&](int i) -> int{
        return N * N + i;
    };
    auto sup_j = [&](int j) -> int{
        return N*N + N + j;
    };
    auto ff = [&](int i, int j) -> int{
        return N*N + N + N + i * N + j;
    };
    rep(i,N)rep(j,N){
        dump(f(i,j));
        dump(sup_i(i));
    }
    auto solve = [&](int maxx){
        int sz = 1 + N*N + N + N + N*N + 1;
        atcoder::mcf_graph<ll,ll> G(sz);
        int s = sz - 2;
        int t = sz - 1;

        const ll inf = 100;
        rep(i,N)rep(j,N){
            G.add_edge(s, f(i,j), 1, inf - A[i][j]);
        }
        rep(i,N)rep(j,N){
            G.add_edge(f(i,j), sup_i(i), 1, 0);
            G.add_edge(f(i,j), sup_j(j), 1, 0);
        }
        rep(i,N)rep(j,N){
            G.add_edge(sup_i(i), ff(i,j), inf, 0);
            G.add_edge(sup_j(j), ff(i,j), inf, 0);
        }
        rep(i,N)rep(j,N){
            G.add_edge(ff(i,j), t, K, 0);
        }
        if(maxx == 0){
            auto [a, b] = G.flow(s, t);
            dump(a, b);
            dump(a * inf - b);
        }
        else{
            auto [a, b] = G.flow(s, t, maxx);
            dump(a, b);
            dump(a * inf - b);
        }
    };
    for(int maxx = 0; maxx <= N*N; maxx++){
        solve(maxx);
    }
}

/*

列と行に容量があるので、スーパーなんたらを手前において、s からKしか流せないという制約をつける


*/
