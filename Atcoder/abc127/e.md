# [ABC127 E - Cell Distance](https://atcoder.jp/contests/abc127/tasks/abc127_e)

## 方針

- xとyは別に計算してあとで足し合わせてよい
- もっと言えば、xとyは対称なので、xについて考えればよい

- 距離は2点間に定義される量なので、K個選ぶとか考えずに、距離dが何回現れるかを考える

- d=0は考える必要がない
- dは1 ~ N-1まで
- その場合の数は、
    - 二点間を固定すると、他の点が選ばれる場合の数の（N*M-2)C(K-2)通りと、
    - x座標の選び方のN-d通りと
    - 選んだ別々のx座標のy座標の選び方でM*M通り
    - のかけ算で求めることができる

## [提出](https://atcoder.jp/contests/abc127/submissions/10706423)
```cpp
#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
typedef long long ll;

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
        return Comb(n + m, m);
    }
};

combination Comb(2e5 + 1);

int main() {

    int N,M,K;
    cin>>N>>M>>K;
    mint ans = 0;
     //x座標の差がdになる場合の数
     rep1(d,N){
         ans += mint(d) * mint(N-d) * mint(M) * mint(M) * Comb.Comb(N*M-2, K-2);
     }
     //y座標の差がdになる場合の数
     rep1(d,M){
         ans += mint(d) * mint(M-d) * mint(N) * mint(N) * Comb.Comb(N*M-2, K-2);
     }
     cout<<ans.x<<endl;
}
```

