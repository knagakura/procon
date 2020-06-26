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
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<ll> A(N);
    rep(i, N)cin >> A[i];
    rep(i,N){
        if(A[i] == 0){
            cout << 0 << endl;
            return 0;
        }
    }
    vector<ll> cnt(N+1, 0);
    vector<ll> tmp(N+1, 0);
    vector<ll> tmp2(N+1, 0);
    int r = 0;
    ll seki = 1;
    rep(l,N){
        while(r < N && seki * A[r] < 1e9){
            seki *= A[r];
            r++;
        }
        cnt[l] += r - l;
        cnt[r] -= r - l;
        tmp[l+1] += -1;
        tmp[r] += 1;
        tmp2[r] += r - l - 1;
        if(l == r)r++;
        else{
            seki /= A[l];
        }
    }
    //print(cnt);
    rep(i,N)cnt[i+1] += cnt[i];
    rep(i,N)tmp[i+1] += tmp[i];

    rep(i,N)tmp[i] += tmp2[i];
    rep(i,N)tmp[i+1] += tmp[i];
    
    rep(i,N)cnt[i] += tmp[i];
    mint ans = 1;
    rep(i,N){
        ans *= mint(A[i]).modpow(cnt[i]);
    }
    cout << ans << endl;
}