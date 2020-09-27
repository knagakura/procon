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
#include <atcoder/modint>
#include <atcoder/lazysegtree>
using mint = atcoder::modint998244353;
const mint inv9 = mint(1)/9;
struct S{
    mint x, w;
    S(mint x = 0, mint w = 1): x(x), w(w) {}; // デフォルト引数は単位元にしておく
};

S op(S a, S b){
    return S(a.x * b.w + b.x, a.w * b.w);
}
S e(){
    return S();
}

// fに変える
S mapping(int f, S a){
    if(f == 0)return a;
    return S((a.w - 1) * inv9 * f ,a.w);
}
int composision(int f, int g){
    if(f == 0)return g; // 0のとき、何もしない
    return f; // gをfに変える
}
int id(){
    return 0;
}
int main() {
    int N, Q;
    cin >> N >> Q;
    atcoder::lazy_segtree<S, op, e, int, mapping, composision, id> t(N);
    rep(i,N){
        t.set(i, S(1, 10));
    }
    rep(qi, Q){
        int l, r, d;
        cin >> l >> r >> d;
        l--;
        t.apply(l, r, d);
        S ans = t.prod(0,N);
        cout << ans.x.val() << endl;
    }
}
