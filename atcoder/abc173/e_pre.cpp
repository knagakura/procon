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
    cout << fixed << setprecision(20);

    int N, K;
    cin >> N >> K;
    vector<ll> s(K,0),f(K,0);
    vector<ll> A;
    int cnt0 = 0;
    rep(i,N){
        ll a;
        cin >> a;
        A.push_back(abs(a));
        if(a == 0)cnt0++;
        if(a > 0){
            s.push_back(a);
        }
        if(a < 0){
            f.push_back(-a);
        }
    }
    if(N - cnt0 < K){
        cout << 0 << endl;
        return 0;
    }
    sort(all(A));
    sort(all(s), greater<>());
    sort(all(f), greater<>());
    //
    mint ans = 1;
    if(N == K){
        rep(i,N){
            ans *= mint(A[i]);
        }
        if((f.size()-K) % 2 == 1){
            ans = -ans;
        }
        cout << ans << endl;
        return 0;
    }
    int idx[] = {0,0};
    if(K&1){
        if(s[0] > 0){
            ans *= s[0];
            idx[0]++;
        }
        // A > 0 がない場合
        else{
            rep(i,K){
                ans *= A[i];
            }
            ans = -ans;
            cout << ans << endl;
            return 0;
        }
        K--;
    }
    rep(_, K/2){
        ll tmp[] = {1,1};
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
    // あと一個を選ぶ
    cout << ans << endl;
}
