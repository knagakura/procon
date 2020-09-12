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


struct Prime{
    int MAXN;
    vector<int> primes;
    vector<int> spf;
    Prime(int MAXN_): MAXN(MAXN_), spf(MAXN_+1){
        spf_init();
    }
    static map<int, int> factorize(int x){
        map<int,int> mp;
        for (int i = 2; i*i <= x; i++){
            while (x%i == 0) {
                x /= i;
                mp[i]++;
            }
            if (x == 1) break;
        }
        if (x != 1) mp[x]++;
        return mp;
    }
    static bool isprime(int v) {
        if (v <= 1) return false;
        if (v == 2) return true;
        for (int i = 2; 1LL * i*i <= v; i++) if (v%i == 0) return false;
        return true;
    }

    // smallest prime factor
    void spf_init(){
        for (int i = 0; i <= MAXN; i++) spf[i] = i;
        for (int i = 2; i * i <= MAXN; i++) {
            // 素数だったら
            if (spf[i] == i) {
                primes.emplace_back(i);
                for (int j = i * i; j <= MAXN; j += i) {
                    // iを持つ整数かつまだ素数が決まっていないなら
                    if (spf[j] == j) {
                        spf[j] = i;
                    }
                }
            }
        }
    }
    // x <= MAXN
    map<int, int> fast_factorize(int x){
        map<int, int> mp;
        while(x != 1){
            mp[spf[x]]++;
            x /= spf[x];
        }
        return mp;
    }
};

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
struct combination {
    vector<mint> fact, ifact;
    //constructor(initiation)
    combination(int n):fact(n+1),ifact(n+1) {
        assert(n < MOD);
        fact[0] = 1;
        for (int i = 1; i <= n; ++i) fact[i] = fact[i-1]*i;
        ifact[n] = fact[n].inv();
        for (int i = n; i >= 1; --i) ifact[i-1] = ifact[i]*i;
    }
    mint Comb(int n, int k) {
        if (k < 0 || k > n) return 0;
        return fact[n]*ifact[k]*ifact[n-k];
    }
    mint H(int n, int m){
        return Comb(n + m - 1, m);
    }
} C(2000010);
int main() {
    ll N;
    cin >> N;
    if(N == 1){
        cout << 1 << endl;
        return 0;
    }
    auto mp = Prime::factorize(N);
    int M = mp.size(); // <= 12
    int yaku_cnt = 1; // 約数の個数
    for(auto p: mp)yaku_cnt *= (p.second + 1);
    ll max_cnt = bit(M) - 1;
    vvec<mint> dp(M+1, vec<mint>(bit(M), 0));
    dp[0][0] = 1;
    for(int i = 0; i < M; i++){
        
    }
    /*
    要素数: i
    最大の割り振り: k
    */
    mint ans = 0;
    for(int i = 1; i <= yaku_cnt; i++){
        mint add = 1;
        for(int k = 1; k <= min(M, i); k++){

        }
        add *= C.fact[i]; // *= i!(並べ替え)
        ans += add;
    }
    cout << ans << endl;
}

/*
関わる素数の数はまあまあ少ない
よって、

*/
