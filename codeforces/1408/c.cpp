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
typedef long double ld;
const int INF = (ll)1e9;
const ll INFLL = (ll)1e18+1;
const ll MOD = 1000000007;
// const ll MOD = 998244353;
const long double PI = acos(-1.0);
const ld eps = 1e-9;
/*
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const string dir = "DRUL";
*/
void solve(){
    int N;
    ld L;
    cin >> N >> L;
    vector<ld> a({0});
    rep(i,N){
        ld x;
        cin >> x;
        a.push_back(x);
    }
    a.push_back(L);
    ld ax = 0, bx = L;
    ld va = 1, vb = 1;
    ld ans = 0;
    dump(a);
    while(ax < bx){
        auto nax = *upper_bound(all(a), ax);
        auto b_itr = lower_bound(all(a), bx);
        if(b_itr != a.begin())b_itr--;
        auto nbx = *b_itr;
        dump(ax, bx);
        dump(nax, nbx);
        dump(va, vb);
        // この時点ではまだ出会わない
        if(nax <= nbx){
            ld dist_a = nax - ax;
            ld dist_b = bx - nbx;
            ld time_a = dist_a / va;
            ld time_b = dist_b / vb;
            ld time = min(time_a, time_b);
            ld dist = (time_a < time_b) ? dist_a: dist_b;
            dump(dist_a, dist_b);
            dump(time_a, time_b);
            ax += time * va;
            bx -= time * vb;
            if(abs(time_a - time_b) < eps){
                ans += time_a;
                va++;
                vb++;
            }
            else if(time_a > time_b){
                ans += time_b;
                vb++;
            }
            else{
                ans += time_a;
                va++;
            }
        }
        // この間で出会う
        else{
            ld dist = abs(ax - bx);
            ans += dist / (va + vb);
            break;
        }
    }
    cout << ans << endl;
}
int main(){
    int t;
    cin >> t;
    while(t--)solve();
}
