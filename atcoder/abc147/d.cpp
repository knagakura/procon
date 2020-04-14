#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define bit(k) (1LL<<(k))
typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = 1e9;
const ll INFLL = 1e18;
const ll MOD = 1e9+7;
const double PI = acos(-1.0);

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

/*------------------------------------/
for library*/
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
 
ll modpow(ll a, ll n, int mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
 
/*------------------------------------*/

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N;
    cin>>N;
    vector<ll> A(N);
    rep(i,N)cin>>A[i];
    ll ans = 0;
    //cum[k][i]
    //k桁目のj番目までもbitの累積和
    vector<vector<int>> cum(60,vector<int>(N+1,0));
    rep(k,60)rep(i,N){
        if(A[i] & bit(k)){
            cum[k][i+1] += cum[k][i]+1;
        }
        else{
            cum[k][i+1] = cum[k][i];
        }
    }
    rep(k,60)rep(i,N-1){
        //反転させてしまう
        int cnt_bit = cum[k][N] - cum[k][i+1];
        int cnt_zer = N - 1 - i - cnt_bit;
        if(A[i] & bit(k)){
            ans += modpow(2,k,MOD) * cnt_zer % MOD;
            ans %= MOD;
        }
        else{
            ans += modpow(2,k,MOD) * cnt_bit % MOD;
            ans %= MOD;
        }
    }
    cout<<ans<<endl;
}