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
template <typename T, typename U> ostream &operator<<(ostream &os, const map<T, U> &mp){ os << "["; for(auto _: mp){ os << _ << ", "; } os << "]"; return os; }

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

int N, M, K;
vector<int> A;
// ある辺i -> jが何回使われたか
int cnt[1111][1111];
vvec<int> G;
map<pair<int, int>, int> mp_e;
vector<pair<int, int>> e;
// mint tdp[1010][200025];
int main() {
    cin >> N >> M >> K;
    A.resize(M);
    rep(i,M){
        cin >> A[i];
        A[i]--;
    }
    rep(i,N)rep(j,N){
        cnt[i][j] = 0;
    }
    G.resize(N);
    rep(i, N-1){
        int u, v;
        cin >> u >> v;
        u--, v--;
        // u < v
        if(u >= v){
            swap(u, v);
        }
        mp_e[{u, v}] = i;
        e.emplace_back(u, v);
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    auto bfs = [&](int s, int t) -> vector<int> {
        queue<int> q;
        vector<int> visited(N, 0);
        vector<int> p(N, -1);
        q.push(s);
        visited[s] = 1;
        while(!q.empty()){
            auto v = q.front();
            q.pop();
            for(auto nv: G[v]){
                if(visited[nv])continue;
                visited[nv] = 1;
                p[nv] = v;
                q.push(nv);
            }
            if(visited[t]){
                break;
            }
        }
        vector<int> res;
        int v = t;
        while(v != -1){
            res.push_back(v);
            v = p[v];
        }
        reverse(all(res));
        return res;
    };

    rep(i,M-1){
        int s = A[i];
        int t = A[i+1];
        vector<int> path = bfs(s, t);
        dump(s, t, path);
        int sz = path.size();
        rep(j, sz-1){
            int l = path[j];
            int r = path[j+1];
            if(l >= r){
                swap(l, r);
            }
            cnt[l][r]++;
        }
    }

    for(auto [l, r]: e){
        dump(l, r, cnt[l][r]);
    }

    // i番目の辺を0/1にしたときの、和がX-1e5になる場合の数 dp[i][X];
    int base = 100005;
    // tdp[0][base] = 1;
    vector<mint> dp(2 * base + 5, 0);
    dp[base] = 1;
    for(int i = 0; i < N-1; i++){
        vector<mint> ndp(2 * base + 5, 0);
        auto [l, r] = e[i];
        for(int j = 0; j < 2 * base; j++){
            // i番目の辺を-1とみなした時
            if(j - cnt[l][r] >= 0){
                ndp[j - cnt[l][r]] += dp[j];
            }
            // +1
            if(j + cnt[l][r] <= 2 * base){
                ndp[j + cnt[l][r]] += dp[j];
            }
        }
        swap(ndp, dp);
    }
    cout << dp[K+base] << endl;
}
