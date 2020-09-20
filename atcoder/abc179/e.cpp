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

/*
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const string dir = "DRUL";
*/

// ll dfs(int l, int r){
//     ll res = 0;
//     if(r - l == 2){
//         ll rui = modpow(X, l+1);
//         res = rui*(1+rui)%M;
//     }
//     else if(r - l == 1){
//         res = modpow(X, l+1);
//     }
//     else{
//         ll mid = (l+r)/2;
//         res = dfs(l, mid) + dfs(mid, r);
//     }
//     // dump(l, r, res);
//     return res;
// }
int main() {
    ll N, X, M;
    cin >> N >> X >> M;
    ll a = X;
    map<ll, int> mp;
    ll sum = a;
    ll cnt = 1;
    vector<ll> cumsum(1, 0);
    cumsum.push_back(a);
    mp[a] = 1;
    while(mp.find((a*a)%M) == mp.end()){
        a *= a;
        a %= M;
        sum += a;
        mp[a] = ++cnt;
        cumsum.push_back(sum);
        if(cnt == N){
            cout << sum << endl;
            return 0;
        }
        dump(a, cnt);
    }
    if(a == 0){
        cout << sum << endl;
        return 0;
    }
    int l_cnt = mp[(a*a)%M]-1;
    int r_cnt = mp[a];
    int len = r_cnt - l_cnt;
    ll ans = cumsum[l_cnt];
    N -= l_cnt;
    ans += N / len * (cumsum[r_cnt] - cumsum[l_cnt]);
    ans += cumsum[l_cnt + N%len] - cumsum[l_cnt];
    cout << ans << endl;
}
