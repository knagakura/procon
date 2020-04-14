#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)

#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
typedef long long ll;

template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;


ll N, M;
struct mint {
    long long x;
    mint(long long _x=0):x((_x%M+M)%M){}
    mint operator-() const { return mint(-x);}
    mint& operator+=(const mint a) {
        if ((x += a.x) >= M) x -= M;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ((x += M-a.x) >= M) x -= M;
        return *this;
    }
    mint& operator*=(const mint a) {
        (x *= a.x) %= M;
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
    mint Mpow(long long t) const {
        if (!t) return 1;
        mint a = Mpow(t>>1);
        a *= a;
        if (t&1) a *= *this;
        return a;
    }
    // for prime M
    mint inv() const {
        return Mpow(M-2);
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

vec<mint> dp, ans;
vvec<int> G;

mint dfs1(int cur, int pre) {
    mint res = 1;
    for(auto& nv: G[cur]){
        if(nv == pre)continue;
        res *= (dfs1(nv, cur) + 1);
    }
    dp[cur] = res;
    return res;
}

//rerooting
void dfs2(int cur, int pre){
    ans[cur] = dp[cur];
    
    int sz = G[cur].size();
    //子のdpの値の左右の累積積
    deque<mint> l(sz+1,1), r(sz+1,1);
    rep(i,sz){
        l[i+1] = l[i] * (dp[G[cur][i]] + 1);
    }
    for(int i = sz-1; i >= 0; i--){
        r[i] = r[i+1] * (dp[G[cur][i]]+1); 
    }
    //print(l);print(r);
    rep(i, sz){
        int nv = G[cur][i];
        if(nv == pre)continue;
        // dp[cur] / dp[nv]をしたいが、modの値が素数でないので逆元は使えない
        //ここで、左右からの累積積を持っておくとそこを除いた計算が素早くできる
        mint tmp_cur = dp[cur];
        mint tmp_nv = dp[nv];
        dp[cur] = l[i] * r[i+1];//親との縁切り　実質割り算
        dp[nv] *= (dp[cur] + 1);//繋ぎかえ　俺が親になってやるぜー
        dfs2(nv, cur);
        dp[cur] = tmp_cur;
        dp[nv] = tmp_nv;
    }
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    cin >> N >> M;
    G.resize(N);
    dp.assign(N, -1);
    ans.resize(N);
    rep(i,N-1){
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs1(0, -1);
    dfs2(0, -1);
    //print(dp);print(ans);
    rep(i,N){
        cout << ans[i] <<endl;
    }
}