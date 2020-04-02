#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define dump(x) cerr<<#x<<": "<<x<<endl;
#define bit(k) (1LL<<(k))
#define Yes "Yes"
#define No "No"
#define YES "YES"
#define NO "NO"
typedef long long ll;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = (ll)1e9;
const ll INFLL = (ll)1e18+1;
const ll MOD = (ll)1e9+7;
const double PI = acos(-1.0);
/*
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const string dir = "DRUL";
*/

template< typename T1, typename T2 >
ostream &operator<<(ostream &os, const pair< T1, T2 > &p) {
    os << "{" << p.first << ", " << p.second << "}";
    return os;
}

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
}C(200100);

template< typename sum_t, typename key_t >
struct ReRooting {
    struct Edge {
        int to;
        key_t data;
        sum_t dp, ndp;
        friend std::ostream& operator<<(std::ostream& os, const Edge& a){
            os << "{" <<a.to << ", " << a.dp << ", " << a.ndp << "}" ;
            return os;
        }
    };
    
    using F = function< sum_t(sum_t, sum_t) >;
    using G = function< sum_t(sum_t, key_t) >;
    
    vector< vector< Edge > > g;
    vector< sum_t > subdp, dp;
    const sum_t ident;
    const F f;
    const G gg;
    
    ReRooting(int V, const F _f, const G _g, const sum_t &_ident)
        : g(V), f(_f), gg(_g), ident(_ident), subdp(V, _ident), dp(V, _ident) {}
    
    void add_edge(int u, int v, const key_t &d) {
        g[u].emplace_back((Edge) {v, d, ident, ident});
        g[v].emplace_back((Edge) {u, d, ident, ident});
    }
    
    void add_edge_bi(int u, int v, const key_t &d, const key_t &e) {
        g[u].emplace_back((Edge) {v, d, ident, ident});
        g[v].emplace_back((Edge) {u, e, ident, ident});
    }
    //葉は{1, 0}が返ってくる
    void dfs_sub(int cur, int pre) {
        for(auto &ne : g[cur]) {
            if(ne.to == pre) continue;
            dfs_sub(ne.to, cur);
            //                         この演算で、後ろは+1される
            subdp[cur] = f(subdp[cur], gg(subdp[ne.to], ne.data));
        }
    }
    
    void dfs_all(int cur, int pre, const sum_t &top) {
        cerr <<endl <<"vertex: " << cur << ", "<< "top: " << top << endl;
        sum_t buff = ident;
        cerr << "to, dp, ndp"<<endl;
        print(g[cur]);
        //全ての子に対しての演算を行いdp[cur]が決定する
        for(int i = 0; i < (int) g[cur].size(); i++) {
            auto &e = g[cur][i];
            e.ndp = buff;//一個前までのbuff結果のメモ
            e.dp = gg(e.to == pre ? top : subdp[e.to], e.data);
            buff = f(buff, e.dp);
            cerr << (e.to == pre ? "親: ": "子: ") << e.to << " " << buff << endl;
        }
        dp[cur] = buff;
        print(dp);
        print(g[cur]);
        buff = ident;
        for(int i = (int) g[cur].size() - 1; i >= 0; i--) {
            auto &e = g[cur][i];
            if(e.to != pre){
                dfs_all(e.to, cur, f(e.ndp, buff));
            }
            e.ndp = f(e.ndp, buff);
            buff = f(buff, e.dp);
        }
    }
    
    vector< sum_t > build() {
        cerr << "sub" << endl;
        dfs_sub(0, -1); 
        print(subdp);
        cerr << "all" <<endl;
        dfs_all(0, -1, ident);
        return dp;
    }
};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N;
    cin >> N;
    //前に場合の数、後ろに自分未満の部分木の頂点数を持つ
    using pi = pair<mint, int>;
    auto  f1 = [&](const pi &a, const pi &b){
        mint res1 = a.first * b.first * C.Comb(a.second + b.second, a.second);
        int  res2 = a.second + b.second;
        return pi(res1, res2);
    };
    //上に上がってくるときに後ろを+1する（自分が含まれていないので）
    auto f2 = [](const pi &a, int b){
        mint res1 = a.first;
        int res2 = a.second + 1;
        return pi(res1, res2);
    };
    ReRooting< pi, int > g(N, f1, f2, pi(1, 0));
    for(int i = 0; i < N-1;i++){
        int a, b;
        cin >> a >> b;
        a--;b--;
        g.add_edge(a, b, 1);
    }
    print(g.dp);
    for(auto &P : g.build()){
        cout << P.first << endl;
    }
}