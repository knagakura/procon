#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define bit(k) (1LL<<(k))

typedef pair<int, int> i_i;
typedef pair<ll, ll> l_l;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;
struct fast_ios{ fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; }fast_ios_;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

#define TOSTRING(x) string(#x)
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (T &x : vec) is >> x; return is; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) { os  << "["; for(auto _: v) os << _ << ", "; os << "]" << endl; return os; };
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

ll chmod(ll x, ll mod){
    if(x < 0)(x %= mod)+=mod;
    return x%mod;
}
int main() {
    ll N;
    cin >> N;
    vector<ll> A(N);
    rep(i,N)cin >> A[i];
    if(N == 1){
        cout << 1 << " " << 1  << endl;
        cout << 1 << endl;
        cout << 1 << " " << 1  << endl;
        cout << 1 << endl;
        cout << 1 << " " << 1  << endl;
        cout << - A[0] - 2 << endl;
        return 0;
    }
    // 1
    ll ans1 = N - chmod(A[0], N);
    A[0] += ans1;
    // 2
    vector<ll> ans2(N);
    rep1(i,N){
        ans2[i] = A[i] * (N-1);
        A[i] += ans2[i];
    }
    // 3回目で全部やる
    cout << 1 << " " << 1 << endl;
    cout << ans1 << endl;
    cout << 2 << " " << N << endl;
    rep1(i,N){cout << ans2[i] << " ";}cout << endl;
    cout << 1 << " " << N << endl;
    rep(i,N){cout << -A[i] << " ";}cout << endl;
}
