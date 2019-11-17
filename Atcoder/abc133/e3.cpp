#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
typedef long long ll;

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


int N,K;
vector<vector<int>> to;
modint ans;
void INPUT(){
    cin>>N>>K;
    ans = K;
    to.resize(N);
    rep(i,N-1){
        int a,b; cin>>a>>b;
        a--;b--;
        to[a].push_back(b);
        to[b].push_back(a);        
    }
}

void dfs(int x, int pre = -1){
    int b = (pre == -1) ? to[x].size() : to[x].size() - 1;
    int c = (pre == -1) ? K-1 : K-2;
    ans *= C(c, b) * fact(b);//cPb
    for(auto nx: to[x]){
        if(nx == pre)continue;
        dfs(nx, x);
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    INPUT();
    dfs(0);
    cout<<ans<<endl;
}
