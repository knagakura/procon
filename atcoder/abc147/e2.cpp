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
// template <class T> using vec = vector<T>;
// template <class T> using vvec = vector<vec<T>>;
template<class T>vector<T> vec(size_t a){return vector<T>(a);}
template<class T, class... Ts>auto vec(size_t a, Ts... ts){return vector<decltype(vec<T>(ts...))>(a, vec<T>(ts...));}
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
    int H, W;
    cin >> H >> W;
    // vvec<int> A(H, vec<int>(W));
    // vvec<int> B(H, vec<int>(W));
    auto A = vec<int>(H, W);
    auto B = vec<int>(H, W);
    cin >> A >> B;
    const int M = 10000 * 2;
    auto dp = vec<int>(H,W,M);
    dp[0][0][abs(A[0][0] - B[0][0])] = 1;
    rep(i,H)rep(j,W)rep(k,M){
        if(dp[i][j][k]){
            if(i + 1 < H){
                dp[i+1][j][k + abs(A[i+1][j] - B[i+1][j])] = 1;
                dp[i+1][j][abs(k - abs(A[i+1][j] - B[i+1][j]))] = 1;
            }
            if(j + 1 < W){
                dp[i][j+1][k + abs(A[i][j+1] - B[i][j+1])] = 1;
                dp[i][j+1][abs(k - abs(A[i][j+1] - B[i][j+1]))] = 1;
            }
        }
    }
    int ans = INF;
    rep(k,M)if(dp[H-1][W-1][k])chmin(ans,k);
    cout << ans << endl;
}
/*
dp[x座標][y座標][そのマスをどっちにぬったか][達成される差]

*/