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
// const ll MOD = 1000000007;
const ll MOD = 998244353;
const long double PI = acos(-1.0);

/*
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const string dir = "DRUL";
*/

struct mint {
    long long x;
    mint(long long _x=0):x((_x%MOD+MOD)%MOD){}
    mint operator-() const { return mint(-x);}
    mint& operator+=(const mint a) {
        if ((x += a.x) >= MOD) x -= MOD;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ((x += MOD-a.x) >= MOD) x -= MOD;
        return *this;
    }
    mint& operator*=(const mint a) {
        (x *= a.x) %= MOD;
        return *this;
    }
    mint operator+(const mint a) const {
        mint res(*this);
        return res+=a;
    }
    mint operator-(const mint a) const {
        mint res(*this);
        return res-=a;
    }
    mint operator*(const mint a) const {
        mint res(*this);
        return res*=a;
    }
    mint modpow(long long t) const {
        if (!t) return 1;
        mint a = modpow(t>>1);
        a *= a;
        if (t&1) a *= *this;
        return a;
    }
    // for prime MOD
    mint inv() const {
        return modpow(MOD-2);
    }
    mint& operator/=(const mint a) {
        return (*this) *= a.inv();
    }
    mint operator/(const mint a) const {
        mint res(*this);
        return res/=a;
    }
    friend std::ostream& operator<<(std::ostream& os, const mint& a){
        os << a.x;
        return os;
    }
};
template<typename T>
class LazySegTree {
  public:
    int N;//葉の数
    vector<T> data;//配列
    vector<T> lazy;//遅延評価
    void _add(int a, int b, T x, int k, int l, int r){
        eval(k, l, r);
        if(b <= l || r <= a)return;
        if(a <= l && r <= b){
            lazy[k] += mint(r - l) * x;
            eval(k, l, r);
        }
        else{
            _add(a, b, x, 2*k+1, l, (l+r)/2);
            _add(a, b, x, 2*k+2, (l+r)/2, r);
            data[k] = data[2*k+1] + data[2*k+2];
        }
    }
    T _query(int a, int b, int k, int l, int r) {
        if(r <= a || b <= l) return 0;
        eval(k, l, r);
        if(a <= l && r <= b) return data[k];
        T c1 = _query(a, b, 2*k+1, l, (l+r)/2);
        T c2 = _query(a, b, 2*k+2, (l+r)/2, r);
        return c1 + c2;
    }
    //コンストラクター
    LazySegTree(vector<T> v){
        int sz = v.size();
        N = 1;
        while(N < sz)N *= 2;
        data.assign(2 * N - 1, 0);
        lazy.assign(2 * N - 1, 0);
        for(int i = 0; i < sz; i++) data[N-1+i] = v[i];
        for(int i = N - 2; i >= 0; i--) data[i] = data[i*2+1] + data[i*2+2];
    }
    //遅延評価
    void eval(int k, int l, int r){
        if(lazy[k].x == 0)return;
        data[k] += lazy[k];
        if(r - l > 1){
            lazy[2*k+1] += lazy[k] / 2;
            lazy[2*k+2] += lazy[k] / 2;
        }
        lazy[k] = 0;
    }
    void add(int a, int b, T x){
        _add(a, b, x, 0, 0, N);
    }
    //[a, b)の区間クエリの実行
    T query(int a, int b){
        return _query(a, b, 0, 0, N);
    }
    //添字でアクセス
    T operator[](int i) {
        return data[i + N - 1];
    }
};

int main() {
    int N, K;
    cin >> N >> K;
    vector<int> l(K), r(K);
    rep(i,K){
        cin >> l[i] >> r[i];
    }
    // vector<mint> dp(N, 0);
    // dp[0] = 1;
    // LazySegTree<mint> T(dp);
    // auto dbug = [&](){
    //     rep(i,N+1){
    //         cerr << T[i] << " ";
    //     }
    //     cout << endl;
    //     return;
    // };
    // rep(i,N){
    //     rep(j,K){
    //         int L = min(N, i+l[j]);
    //         int R = min(N, i+r[j]);
    //         dump(L, R);
    //         T.add(L, R+1, T[i]);
    //     }
    //     dbug();
    //     cerr << endl;
    // }
    // cout << T[N-1] << endl;
    vector<mint> dp(N+10, 0);
    dp[0] = 1;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < K; j++){
            int L = min(N, i + l[j]);
            int R = min(N+1, i + r[j])+1;
            dump(L,R);
            dp[L] += dp[i];
            dp[R] -= dp[i];
        }
        if(i)dp[i+1] += dp[i];
    }
    cout << dp[N-1] << endl;
}
