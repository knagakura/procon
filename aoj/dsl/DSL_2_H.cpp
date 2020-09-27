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
#include <atcoder/lazysegtree>

// struct S{
//     ll x;
//     ll size;
//     S(ll x_ = 0, ll size_ = 0): x(x_), size(size_){};
// };
// struct F{
//     ll x;
//     F(ll x_ = 0): x(x_){};
// };

// S op(S a, S b){
//     return S(min(a.x, b.x), a.size + b.size);
// }
// S e(){
//     return S(INF, 0);
// }
// S mapping(F a, S b){
//     return S(b.x + a.x /** b.size*/, b.size);
// }
// F composition(F a, F b){
//     return F(a.x + b.x);
// }
// F id(){
//     return F();
// }
using S = ll;
using F = ll;
S op(S a, S b){ return std::min(a, b); }
S e(){ return INFLL; }
S mapping(F f, S x){ return f+x; }
F composition(F f, F g){ return f+g; }
F id(){ return 0; }

int main() {
    int N, Q;
    cin >> N >> Q;
    // atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> T(N);
    // rep(i,N)T.set(i, S(0, 1));

    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> T(N);
    rep(i,N)T.set(i, 0);
    // auto outs = [&](){
    //     rep(i,N){
    //         cerr << "{" << T.get(i).x << " " << T.get(i).size << "}, ";
    //     }
    //     cerr << endl;
    // };
    while(Q--){
        int type;
        cin >> type;
        if(type == 0){
            int l, r;
            ll x;
            cin >> l >> r >> x;
            T.apply(l, r+1, F(x));
            // for(int i = l; i <= r; i++){
            //     dump(i, T.get(i).x);
            // }
        }
        else{
            int l, r;
            cin >> l >> r;
            // cout << T.prod(l, r+1).x << endl;
            cout << T.prod(l, r+1) << endl;
        }
    }
}
