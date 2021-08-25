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

const int INF = (ll)1e5;
const ll INFLL = (ll)1e18+1;
const ll MOD = 1000000007;
// const ll MOD = 998244353;
const long double PI = acos(-1.0);

/*
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const string dir = "DRUL";
*/


int dp[444][444];
pair<int, int> pdp[444][444];
int main() {
    string S, T;
    cin >> S >> T;
    int N = S.size();
    int M = T.size();
    rep(i,N+1)rep(j,M+1){
        dp[i][j] = -INF;
        pdp[i][j] = {-1,-1};
    }
    dp[0][0] = 0;
    pdp[0][0] = {-1, -1};
    rep(i,N+1){
        rep(j,M+1){
            if(chmax(dp[i+1][j], dp[i][j] - 5)){
                pdp[i+1][j] = {i, j};
            }
            if(chmax(dp[i][j+1], dp[i][j] - 5)){
                pdp[i][j+1] = {i, j};
            }
            if(S[i] == T[j]){
                if(chmax(dp[i+1][j+1], dp[i][j] + 1)){
                    pdp[i+1][j+1] = {i, j};
                }
            } else {
                if(chmax(dp[i+1][j+1], dp[i][j] - 3)){
                    pdp[i+1][j+1] = {i, j};
                }
            }
        }
    }
    // 復元
    string ans1;
    string ans2;
    int x = N;
    int y = M;
    while(true){
        dump(x, y);
        if(x == 0 && y == 0)break;
        auto [px, py] = pdp[x][y];
        if(x-1 == px && y-1 == py){
            ans1.push_back(S[x-1]);
            ans2.push_back(T[y-1]);
        }
        if(x == px && y-1 == py){
            ans1.push_back('-');
            ans2.push_back(T[y-1]);
        }
        if(x-1 == px && y == py){
            ans1.push_back(S[x-1]);
            ans2.push_back('-');
        }
        x = px, y = py;
    }
    reverse(all(ans1));
    reverse(all(ans2));
    assert(ans1.size() == ans2.size());
    dump(N, M, dp[N][M]);
    // rep(i,N+1){
    //     rep(j,M+1){
    //         cerr << dp[i][j] << " ";
    //     }
    //     cerr << endl;
    // }
    cout << ans1 << endl;
    cout << ans2 << endl;
}
