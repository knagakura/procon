#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
typedef long long ll;


const ll MOD = (ll)998244353;
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
mint dp[3010][3010];
int main() {

    int N, S;
    cin >> N >> S;
    vector<int> A(N);
    rep(i,N)cin>>A[i];
    rep(i,N)rep(j,S+1)dp[i][j] = 0;
    rep(i,N)dp[i][0] = 1;
    rep(i,N)rep(j,S+1){
        dp[i+1][j] += dp[i][j];
        dp[i+1][min(S+1, j + A[i])] += dp[i][j];
    }
    mint ans = 0;
    rep(i,N+1)ans += dp[i][S];
    cout << ans << endl;
    
}