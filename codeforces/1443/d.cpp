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
    vector<int> a(N);
    cin >> a;
    dump(a);
    int sz = *max_element(all(a))+1;
    vvec<int> v(sz);
    rep(i,N){
        v[a[i]].emplace_back(i);
    }
    //--------
    rep(i,sz){
        if(not v[i].empty()){
            dbg(i, v[i]);
        }
    }
    //--------
    bool ok = true;
    rep(i,sz){
        if(not v[i].empty()){
            int M = v[i].size();
            dump(i);
            if(M == 1)break;
            if(M > 1){
                dump(M);
                rep(j,M-1){
                    dump(j);
                    int x = v[i][j];
                    int y = v[i][j+1];
                    int maxx = 0;
                    for(int k = x+1; k < y; k++){
                        dump(k);
                        chmax(maxx, a[k]-i);
                    }
                    dump(x, y, maxx);
                    if(M == 2){
                        if(maxx >= 2)ok = false;
                    }
                    else{
                        ok = false;
                    }
                }
            }
            break;
        }
    }
    cout << (ok ? "YES": "NO") << endl;;
    cerr << endl;
}
int main(){
    int t;
    cin >> t;
    while(t--)solve();
}
