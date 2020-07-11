#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
typedef long long ll;
const ll MOD = 1e9 + 7;
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


int main() {
    ll N, K;
    cin >> N >> K;
    vector<ll> s(2e5,0), f(2e5,0);
    vector<ll> A;
    ll cntz = 0, cntpl = 0, cntmi = 0;
    rep(i,N){
        ll a;
        cin >> a;
        A.push_back(abs(a));
        if(a == 0)cntz++;
        if(a > 0){
            s.push_back(a);
            cntpl++;
        }
        if(a < 0){
            f.push_back(abs(a));
            cntmi++;
        }
    }
    sort(all(A));
    sort(all(s), greater<>());
    sort(all(f), greater<>());
    mint ans = 1;
    if(N == K){
        rep(i,K)ans *= A[i];
        if(cntmi & 1)ans = -ans;
        cout << ans << endl;
        return 0;
    }
    // K < N;
    ll idx[] = {0,0};
    if(K&1){
        if(cntpl > 0)ans *= s[idx[0]++];
        else{
            rep(i,K)ans *= A[i];
            ans = -ans;
            cout << ans << endl;
            return 0;
        }
    }
    // 残りの偶数個を決めていく
    ll len = K / 2;
    while(len--){
        ll tmp[2];
        tmp[0] = s[idx[0]] * s[idx[0]+1];
        tmp[1] = f[idx[1]] * f[idx[1]+1];
        if(tmp[0] < tmp[1]){
            ans *= tmp[1];
            idx[1] += 2;
        }
        else{
            ans *= tmp[0];
            idx[0] += 2;
        }
    }
    cout << ans << endl;
}
