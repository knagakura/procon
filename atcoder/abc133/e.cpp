#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }

typedef long long ll;

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = 1e9;
const ll INFLL = 1e18;
const ll MOD = 1e9+7;

const double PI = acos(-1.0);
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
    static modint P(ll n, ll r){
        if(n<0)return 0;
        return n >= r ? fact(n)/(fact(n-r)): modint(0);
    }
};
vector<modint> modint::factorial;
#define fact(n) modint::fact(n)
#define C(n,r) modint::C(n,r)
#define P(n,r) modint::P(n,r)
#define H(a,b) C(a+b, a)

int N,K;
vector<vector<int>> G;
modint ans = 1;
void dfs(int x, int pre, int d){
    print(G[x]);
    cerr<<x<<endl;
    cerr<<ans<<endl;
    ll bro = G[x].size()-1;
    if(d == 0){
        ans *= K;
    }
    else if(d == 1){
        ans *= P(K-1,bro);
    }
    else{
        ans *= P(K-2, bro);
    }
    for(auto nx: G[x]){
        if(nx == pre)continue;
        dfs(nx, x, d+1);
    }
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    cin>>N>>K;
    G.resize(N);
    rep(i,N-1){
        int a,b; cin>>a>>b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(0,-1,0);
    cout<<ans<<endl;
}