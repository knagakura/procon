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
const ll INFLL = (ll)1e12;
const ll MOD = 1000000007;
// const ll MOD = 998244353;
const long double PI = acos(-1.0);

/*
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const string dir = "DRUL";
*/
#include <atcoder/mincostflow>

ll a[3], b[3];
int main() {
    ll N;
    cin >> N;
    atcoder::mcf_graph<ll, ll> G_min(20); //価値の最小値
    atcoder::mcf_graph<ll, ll> G_max(20);
    rep(i,3)cin >> a[i];
    rep(i,3)cin >> b[i];
    int s = 6;
    int t = s + 1;
    rep(i,3){
        G_min.add_edge(s, i, INF, 0);
        G_min.add_edge(i+3, t, b[i], 0);
        //
        G_max.add_edge(s, i, INF, 0);
        G_max.add_edge(i+3, t, b[i], 0);
    }
    rep(i,3)rep(j,3){
        int a_i = i;
        int b_i = j + 3;
        int cost = 0;
        if(a_i == 0 && b_i == 4)cost++;
        if(a_i == 1 && b_i == 5)cost++;
        if(a_i == 2 && b_i == 3)cost++;
        G_min.add_edge(a_i, b_i, a[i], cost);
        //
        G_max.add_edge(a_i, b_i, a[i], INFLL-cost);
    }
    auto ans_min = G_min.flow(s, t, N);
    auto ans_max = G_max.flow(s, t, N);
    dump(ans_min);
    dump(ans_max);
    cout << ans_min.second << " " << ans_max.first * INFLL - ans_max.second << endl;
    // cout << ans_min << " " << ans_max << endl;
}
