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
const long double eps=1e-12;
/*
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const string dir = "DRUL";
*/


int main() {
    int N;
    ll D;
    cin >> N >> D;
    map<int, int> mp;
    vector<int> a({2,3,5});
    rep(i,3){
        mp[a[i]] = 0;
        while(D % a[i] == 0){
            mp[a[i]]++;
            D /= a[i];
        }
    }
    if(D > 1){
        cout << 0 << endl;
        return 0;
    }
    const int M = 65;
    vector<vector<vector<long double>>> dp(M, vector<vector<long double>>(M, vector<long double>(M,0)));
    dp[0][0][0] = 1;
    rep(i,N){
        vector<vector<vector<long double>>> dp2(M, vector<vector<long double>>(M, vector<long double>(M,0)));
        rep(j,mp[2]+1)rep(k,mp[3]+1)rep(l,mp[5]+1){
            {
                dp2[j][k][l] += dp[j][k][l]/6.0;
            }
            {
                dp2[min(mp[2],j+1)][k][l] += dp[j][k][l]/6.0;
            }
            {
                dp2[j][min(mp[3],k+1)][l] += dp[j][k][l]/6.0;
            }
            {
                dp2[min(mp[2],j+2)][k][l] += dp[j][k][l]/6.0;
            }
            {
                dp2[j][k][min(mp[5], l+1)] += dp[j][k][l]/6.0;
            }
            {
                dp2[min(mp[2], j+1)][min(mp[3],k+1)][l] += dp[j][k][l]/6.0;
            }
        }
        swap(dp, dp2);
    }
    cout << dp[mp[2]][mp[3]][mp[5]] << endl;
}
