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
const ll INFLL = (ll)1e18+1;
const ll MOD = 1000000007;
// const ll MOD = 998244353;
const long double PI = acos(-1.0);

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};


ll v[3010][3010];
ll dp[3010][3010][10];
int main() {
    int H, W, K;
    cin >> H >> W >> K;
    rep(i,H)rep(j,W)v[i][j] = 0;
    while(K--){
        int x, y;
        ll val;
        cin >> x >> y >> val;
        x--, y--;
        v[x][y] = val;
    }
    auto isin = [&](int a, int b) -> bool{
        return 0 <= a && a < H && 0 <= b && b < W;
    };
    rep(i,H)rep(j,W)rep(k,10)dp[i][j][k] = 0;
    dp[0][0][0] = 0;
    dp[0][0][1] = v[0][0];
    rep(i,H)rep(j,W)rep(k,4){
        rep(d,2){
            int ni = i + dx[d];
            int nj = j + dy[d];
            if(not isin(ni, nj))continue;
            // 行変え
            if(d == 0){
                // 取る
                chmax(dp[ni][nj][1], dp[i][j][k] + v[ni][nj]);
                // 取らない
                chmax(dp[ni][nj][0], dp[i][j][k]);
            }
            // 同じ行
            else{
                // 取る
                chmax(dp[ni][nj][k+1], dp[i][j][k] + v[ni][nj]);
                // 取らない
                chmax(dp[ni][nj][k], dp[i][j][k]);
            }
        }
    }
    ll ans = 0;
    rep(k,4)chmax(ans, dp[H-1][W-1][k]);
    cout << ans << endl;
}
