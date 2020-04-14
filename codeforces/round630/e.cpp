#include <iostream>
using namespace std;
typedef long long ll;
const ll MOD = 998244353;

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

    ll n, m, l, r;
    cin >> n >> m >> l >> r;
    mint ans;
    mint total_grid_num = mint(r - l + 1).modpow(n * m);
    if(n * m % 2 == 1){
        ans = total_grid_num;
    }
    else{
        if((r - l + 1) % 2 == 0){
            ans = total_grid_num * mint(2).inv();
        }
        else{
            ans = (total_grid_num - 1) * mint(2).inv() + 1;
        }
    }
    cout << ans << endl;
}