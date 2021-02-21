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
    ll B, C;
    cin >> B >> C;
    vector<pair<ll, ll>> vp; // 閉区間
    // 1. 単純に1引き続ける
    ll l = B - C / 2;
    ll r = B;
    vp.emplace_back(l, r);
    if(C%2 == 0){
        vp.emplace_back(-r, -l-1);
    }
    else{
        vp.emplace_back(-r, -l);
    }
    dump(l, r);
    // 2. 最初に-1倍してから、1引き続ける
    ll l2 = -B - (C-1)/2;
    ll r2 = -B;
    dump(l2, r2);
    vp.emplace_back(l2, r2);
    if((C-1)%2 == 0){
        vp.emplace_back(-r2, -l2-1);
    }
    else{
        vp.emplace_back(-r2, -l2);
    }
    sort(all(vp));
    dump(vp);
    ll ans = 0;
    int sz = vp.size();
    ll L = vp[0].first;
    ll R = vp[0].second;
    rep(i,sz){
        if(i == sz-1){
            ans += R - L + 1;
        }else{
            if(vp[i].second >= vp[i+1].first){
                R = vp[i+1].second;
            }
            else{
                ans += R - L + 1;
                L = vp[i+1].first;
                R = vp[i+1].second;
            }
        }
    }
    cout << ans << endl;
}
