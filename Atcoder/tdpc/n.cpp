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
int N;
vec<mint> dp, ans;
vvec<int> G;
vec<int> sub;

//cur以下の部分木の頂点数 sub[cur]
int dfs0(int cur = 0, int pre = -1){
    int res = 1;
    for(auto& nv: G[cur]){
        if(nv == pre)continue;
        res += dfs0(nv, cur);
    }
    return sub[cur] = res;
}

//from 0のdpを求める
mint dfs1(int cur = 0, int pre = -1) {
    mint res = C.fact[sub[cur]-1];
    for(auto& nv: G[cur]){
        if(nv == pre)continue;
        res *= C.ifact[sub[nv]];
        res *= (dfs1(nv, cur));
    }
    return dp[cur] = res;
}

void dfs2(int cur = 0, int pre = -1){
    //cerr << pre+1 <<  " -> " << cur+1 << endl;
    //print(dp);
    //print(G[cur]);
    for(auto& nv: G[cur]){
        if(nv == pre)continue;
        mint tmp1 = dp[cur];
        mint tmp2 = dp[nv];

        int tmp_sub1 = sub[cur];
        int tmp_sub2 = sub[nv];

        sub[cur] -= sub[nv];
        sub[nv] =  N;
        //
        dp[cur] *= tmp2.inv(); //dpの値を消す
        dp[cur] *= C.fact[tmp_sub2]; //分母の階乗を消す
        dp[cur] *= C.fact[tmp_sub1-1].inv();// 分子を一旦消す
        dp[cur] *= C.fact[sub[cur]-1];//階上を小さくしてかけ算

        dp[nv] *= dp[cur];// 更新された親のdpの値をかける
        dp[nv] *= C.fact[sub[cur]].inv();//分母に追加
        dp[nv] *= C.fact[tmp_sub2-1].inv();//一旦分子を消す
        dp[nv] *= C.fact[sub[nv]-1];//分子に大きくしてかける
        dfs2(nv, cur);
        //
        dp[cur] = tmp1;
        dp[nv] = tmp2;
        sub[cur] = tmp_sub1;
        sub[nv] = tmp_sub2;
        //cerr << nv+1 <<" -> " << cur+1 << endl;
    }
    ans[cur] = dp[cur];
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    cin >> N;
    G.resize(N);

    rep(i,N-1){
        int a,b;
        cin >> a >> b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    sub.resize(N);
    dfs0();
    //print(sub);

    dp.assign(N,-1);
    dfs1();
    //print(dp);
        
    ans.resize(N);
    dfs2();
    mint res = 0;
    rep(i,N){
        res += ans[i];
    }
    //print(ans);
    cout << res / 2 << endl;
}