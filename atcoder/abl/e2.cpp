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
#include <atcoder/modint>
using mint = atcoder::modint998244353;

vector<mint> pow10;
const mint inv9 = mint(9).inv();

// モノイド
struct S{
    mint x;
    int size;
    S(mint x_ = 0, int size_ = 0): x(x_), size(size_){}
};

// 関数に必要係数等
struct F{
    int x;
    F(int x_ = 0): x(x_){}
};

// モノイドの演算(結合律を満たす)
S op(S a, S b){
    mint nxt_x = a.x * pow10[b.size] + b.x; // 
    return S(nxt_x, a.size + b.size);
}

// モノイドの単位元
S e(){
    return S(0, 0);
}

// S -> Sの写像 f
S mapping(F f, S g){
    if(f.x == 0)return g;
    return S(f.x * (pow10[g.size] - 1) * inv9, g.size); // 数字 * 1111...1
}

// 写像の合成
F composition(F f, F g){
    if(f.x == 0)return g;
    return f;
}

// 恒等写像(f(id) = id)
F id(){
    return F(0);
}
int main() {
    int N, Q;
    cin >> N >> Q;
    pow10.resize(N+5);
    pow10[0] = 1;
    rep(i,N+3)pow10[i+1] = pow10[i] * 10;
    atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> T(N);
    rep(i,N)T.set(i, S(1, 1));
    while(Q--){
        int l, r, d;
        cin >> l >> r >> d;
        l--, r--;
        T.apply(l, r+1, F(d));
        printf("%d\n", T.all_prod().x.val());
    }
}
