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
void solve(){
    int N;
    cin >> N;
    vector<ll> a(N);
    rep(i,N)cin >> a[i];
    ll sum = SUM(a);
    dump(sum, a);
    if(sum % N != 0){
        cout << -1 << endl;
        return;
    }
    ll ave = sum / N;
    ll cnt = 0;
    vector<ll> p, q, r;
    rep1(i,N){
        ll x = a[i] / (i+1);
        // cout << i+1 << " " << 1 << " " << x << endl;
        p.push_back(i+1);
        q.push_back(1);
        r.push_back(x);
        a[i] -= (i+1) * x;
        a[0] += (i+1) * x;
        dump(a);
    }
    for(int i = N-1; i >= 1; i--){
        if(a[i] > ave){
            // ll x = a[i] - ave;
            ll mod = a[i] % (i+1); // > 0
            ll x = (i+1) - mod;
            // cout << 1 << " " << i+1 << " " << x << endl;
            p.push_back(1);
            q.push_back(i+1);
            r.push_back(x);
            a[i] += x;
            a[0] -= x;
            ll y = a[i];
            // cout << i + 1 <<  " " << 1 << " " << y / (i+1) << endl;
            p.push_back(i+1);
            q.push_back(1);
            r.push_back(y/(i+1));
            a[i] -= y;
            a[0] += y;
            dump(a);
        }
    }
    rep1(i,N){
        ll y = ave - a[i];
        // cout << 1 << " " << i+1 << " " << y << endl;
        p.push_back(1);
        q.push_back(i+1);
        r.push_back(y);
        a[i] += y;
        a[0] -= y;
    }
    int M = p.size();
    cout << M << endl;
    rep(i,M){
        cout << p[i] << " " << q[i] << " " << r[i] << endl;
    }
}
int main(){
    int t;
    cin >> t;
    while(t--)solve();
}
