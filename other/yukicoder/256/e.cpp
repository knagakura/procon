#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
typedef long long ll;
typedef pair<ll, ll> l_l;
const ll MOD = (ll)1e9+7;

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
// dp[i][j]:i個決めたときの複雑さjの個数
// ans = dp[N][K];
// その前がなんのコードだったかを持たないといけないからdp[i][j][k]になるか？
// 300 ^ 4になって間に合わない
// コード進行は有向グラフに落ちるので、そこからなんかできないかなー

// bfsで探索しながら、N-1回遷移したら終わる感じにしたらどう？
const int sz = 333;
mint dp[sz][sz][sz];
int main() {
    ll N, M, K;
    cin >> N >> M >> K;
    vvec<l_l> G(sz);
    rep(i,M){
        ll p, q, c;
        cin >> p >> q >> c;
        p--, q--;
        G[p].push_back({q, c});
    }
    rep(i,sz)rep(j,sz)rep(k,sz)dp[i][j][k] = 0;

    mint ans = 0;

    /* calc */
    // {頂点,移動回数,複雑度合計,個数}
    queue<pair<l_l,pair<ll, mint>>> q;
    rep(i,sz)q.push({{i, 1}, {0, 1}});
    rep(i,sz)dp[i][1][0] =1;
    while(not q.empty()){
        auto tmp = q.front();
        q.pop();
        int cur = tmp.first.first;
        int cnt = tmp.first.second;
        ll sum = tmp.second.first;
        mint dp_sum = tmp.second.second;
        if(cnt == N)continue;
        if(dp_sum.x != dp[cur][cnt][sum].x)continue;
        for(auto &p: G[cur]){
            int nxt = p.first;
            int C = p.second;
            if(sum + C > K)continue;
            dp[nxt][cnt+1][sum + C] += dp_sum;
            q.push({{nxt, cnt+1},{sum + C, dp[nxt][cnt+1][sum + C]}});
        }
    }
    rep(i,sz){
        ans += dp[i][N][K];
    }
    cout << ans << endl;
}
