#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()        //sort(all(vi S)) sort(all(string S))
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }

using P = pair<int, int>;        //P.first, P.second
typedef long long ll;
typedef vector<int> vi;
typedef set<int> seti;
typedef vector<string> vs;

const int MOD = 1e9+7;
const int INF = 1e9;

class modint {
  public:
    using ll = long long;
    ll num;
    static const ll MOD = 1e9+7;
    static vector<modint> factorial;
    modint(): num(0) {};
    modint(ll _n): num((_n + MOD) % MOD) {}
    modint(const modint &r): num(r.num) {}
    operator ll() const { return (num+MOD)%MOD; }
    friend istream& operator>>(istream& is, modint &r){
        ll num_;
        is >> num_;
        r = num_;
        return is;
    }
    modint operator+(const modint &r) const { return modint(num + r.num); }
    modint operator-(const modint &r) const { return modint(num - r.num); }
    modint operator*(const modint &r) const { return modint(num * r.num); }
    template<typename T>
    modint operator^(const T &r) const {
        if(r == 0) return 1;
        return (((*this)*(*this)) ^ (r/2)) * modint(r&1 ? num : 1);
    }
    modint operator/(const modint &r) const { return num * (r^(MOD-2)); }
    modint operator+=(const modint &r) { return *this = *this + r; }
    modint operator-=(const modint &r) { return *this = *this - r; }
    modint operator*=(const modint &r) { return *this = *this * r; }
    modint operator/=(const modint &r) { return *this = *this / r; }
    template<typename T>
    modint operator^=(const T &r) { return *this = *this ^ r; }
    static modint fact(int n){
        if((int)factorial.size() <= n) factorial.resize(n+1);
        if(factorial[n]) return factorial[n];
        if(n == 0) return 1;
        return factorial[n] = modint(n) * fact(n-1);
    }
    static modint C(ll n,ll r){
        return n >= r ? fact(n)/(fact(n-r)*fact(r)) : modint(0);
    }
};
vector<modint> modint::factorial;
#define fact(n) modint::fact(n)
#define C(n,r) modint::C(n,r)
#define H(a,b) C(a+b, a)

int main() {
    ll N,K;
    cin>>N>>K;
    rep1(i,K+1){
        ll ans = 1;
        ans *= C(K-1,i-1)%MOD;
        ans *= C(N-K+1,i)%MOD;
        ans %= MOD;
        cout<<ans<<endl;
    }
}