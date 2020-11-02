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


int main() {
    int N, M;
    cin >> N >> M;
    vector<ll> a(N), b(M);
    cin >> a >> b;
    sort(all(a));
    vector<ll> d0(N+3), cum0(N+3);
    vector<ll> d1(N+3), cum1(N+3);
    for(int i = 0; i < N; i += 2){
        d0[i/2] = a[i+1] - a[i];
    }
    for(int i = 1; i+1 < N; i+= 2){
        d1[i/2] = a[i+1] - a[i];
    }
    rep(i,N){
        cum0[i+1] = cum0[i] + d0[i];
    }
    rep(i,N){
        cum1[i+1] = cum1[i] + d1[i];
    }
    auto calc = [&](ll x) -> ll{
        ll res = 0;
        int idx = lower_bound(all(a), x) - a.begin();
        if(idx % 2 == 0){
            res += a[idx] - x;
            res += cum0[idx/2];
            res += cum1[N/2] - cum1[idx/2];
        }
        else{
            res += x - a[idx-1];
            res += cum0[idx/2];
            res += cum1[N/2] - cum1[idx/2];
        }
        return res;
    };
    ll ans = INFLL;
    rep(i,M){
        chmin(ans, calc(b[i]));
    }
    cout << ans << endl;
}
