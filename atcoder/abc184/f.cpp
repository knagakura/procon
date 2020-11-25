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
template <typename T, typename U> ostream &operator<<(ostream &os, const map<T, U> &mp){ os << "["; for(auto _: mp){ os << _ << ", "; } os << "]" << endl; return os; }

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


int main() {
    int N, T;
    cin >> N >> T;
    vector<ll> A(N);
    rep(i,N)cin >> A[i];
    sort(all(A));
    int n = N / 2;
    int m = N - n;
    vector<ll> v;
    vector<ll> v2;
    for(int i = 0; i < bit(n); i++){
        ll summ = 0;
        rep(j,n){
            if(i&bit(j)){
                summ += A[j];
            }
        }
        v.emplace_back(summ);
    }
    for(int i = 0; i < bit(m); i++){
        ll summ = 0;
        rep(j,m){
            if(i&bit(j)){
                summ += A[n+j];
            }
        }
        v2.emplace_back(summ);
    }
    dump(v);
    dump(v2);
    ll ans = 0;
    int sz = v.size();
    sort(all(v2));
    rep(i,sz){
        ll rem = T - v[i];
        if(rem < 0)continue;
        int idx = lower_bound(all(v2), rem) - v2.begin();
        // if(idx == v2.size())continue;
        idx--;
        ll a = v2[idx];
        dump(v[i], rem, idx, a);
        if(v[i] + a <= T){
            chmax(ans, v[i] + a);
        }
        if(idx + 1 < v2.size()){
            if(v[i] + v2[idx+1] <= T){
                chmax(ans, v[i]+v2[idx+1]);
            }
        }
    }
    cout << ans << endl;
}
