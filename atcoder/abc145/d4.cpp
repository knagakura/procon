#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

class modint {
  public:
    using ll = long long;
    ll num;
    static const ll MOD = 1e9 + 7;
    static vector<modint> factorial;
 
    modint(): num(0) {};
    modint(ll num_): num((num_ + MOD) % MOD) {
        assert(num >= 0);
    }
    modint(const modint &r): num(r.num) {}
    operator ll() const { return num; }
 
    template <typename T>
    void check_type(const T &num_) const {
        assert(num_ >= 0 && num_ < MOD);
        static_assert(is_integral<T>() || is_same<T,modint>(), "T is not integral.");
    }
 
    template <typename T>
    modint operator+(const T &r) const { check_type(r); return num + r; }
    template <typename T>
    modint operator-(const T &r) const { check_type(r); return num - r; }
    template <typename T>
    modint operator*(const T &r) const { check_type(r); return num * r; }
    template <typename T>
    modint operator/(const T &r) const { check_type(r); return num * pow(r, MOD-2); }
 
    template <typename T>
    modint operator+=(const T &r) { return *this = *this + r; }
    template <typename T>
    modint operator-=(const T &r) { return *this = *this - r; }
    template <typename T>
    modint operator*=(const T &r) { return *this = *this * r; }
    template <typename T>
    modint operator/=(const T &r) { return *this = *this / r; }
 
    static modint pow(const modint &x, const ll &r) {
        if(r == 0) return 1;
        return pow(x*x, r/2) * modint(r&1 ? x : modint(1));
    }
 
    static modint fact(int n){
        if((int)factorial.size() <= n) {
            int size = factorial.size();
            factorial.resize(n+1);
            for (int k = size; k <= n; k++) {
                factorial[k] = factorial[k-1] * k;
            }
        }
        return factorial[n];
    }
 
    static modint C(int n, int r){
        return n >= r ? fact(n)/(fact(n-r)*fact(r)) : modint(0);
    }
 
    friend istream& operator>>(istream& is, modint &r){
        ll num_;
        is >> num_;
        r = num_;
        return is;
    }
};
vector<modint> modint::factorial = {1};
#define fact(n) modint::fact(n)
#define C(n,r) modint::C(n,r)
#define H(a,b) C(a+b, a)
 
 
int main() {
    int X,Y;
    cin>>X>>Y;
    int x = 2 * Y - X;
    int y = 2 * X - Y;
    ll ans;
    if(x >= 0 && y >= 0 && x % 3 == 0 && y % 3 ==0){
        x /= 3;
        y /= 3;
        ans = H(x,y);
    }
    else{
        ans = 0;
    }
    cout<<ans<<endl;
}