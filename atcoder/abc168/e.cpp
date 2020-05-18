#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define dump(x) cerr<<#x<<": "<<x<<endl;
#define bit(k) (1LL<<(k))
typedef long long ll;
typedef pair<int, int> i_i;
typedef pair<ll, ll> l_l;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;
template< typename T1, typename T2 >
ostream &operator<<(ostream &os, const pair< T1, T2 >& p) {
  os << "{" <<p.first << ", " << p.second << "}";
  return os;
}
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = (ll)1e9;
const ll INFLL = (ll)1e18+1;
const ll MOD = (ll)1e9+7;
const double PI = acos(-1.0);
/*
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const string dir = "DRUL";
*/
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
ll gcd(ll a,ll b){
    if(b == 0) return a;
    return gcd(b, a%b);
}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll N;
    cin >> N;
    vector<ll> A(N),B(N);
    map<pair<ll, l_l>, ll> mp;
    rep(i,N){
        cin >> A[i] >> B[i];
        if(A[i] == 0 && B[i] == 0){
            mp[{0, {0LL,0LL}}]++;
            continue;
        }
        if(A[i] == 0 && B[i] != 0){
            mp[{2, {0,1}}]++;
            continue;
        }
        if(A[i] != 0 && B[i] == 0){
            mp[{-2, {1,0}}]++;
            continue;
        }
        ll G = gcd(abs(A[i]), abs(B[i]));
        A[i] /= G;
        B[i] /= G;
        if((A[i] < 0 && B[i] > 0) || (A[i] > 0 && B[i] < 0)){
            mp[{-1,{abs(A[i]),abs(B[i])}}]++;
        }
        if((A[i] > 0 && B[i] > 0) || (A[i] < 0 && B[i] < 0)){
            mp[{1,{abs(A[i]),abs(B[i])}}]++;
        }
    }
    mint ans = 1;
    //print(mp);
    mint ori = 0;
    for(auto &p: mp){
        int fugo = p.first.first;
        ll a = p.first.second.first;
        ll b = p.first.second.second;
        ll cnt = p.second;
        if(cnt == -1)continue; 
        if(cnt == 0)continue;
        //dump(p);
        if(fugo == 0){
            ori = cnt;
            continue;
        }
        pair<ll, l_l> gyaku = {-fugo, {b,a}};
        //逆符号で、逆にやつ{-fugo, {b,a}}が存在するかどうか
        if(mp[gyaku] > 0){
            //dump(gyaku);
            ll cnt2 = mp[gyaku];
            ans *= mint(2).modpow(cnt) + mint(2).modpow(cnt2) - 1;
            mp[gyaku] = -1;
        }
        else{
            ans *= mint(2).modpow(cnt);
        }
    }
    ans += ori;
    ans = ans - 1;
    cout << ans << endl;
}