#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define dump(x) cerr<<#x<<": "<<x<<endl;
#define bit(k) (1LL<<(k))
#define Yes "Yes"
#define No "No"
#define YES "YES"
#define NO "NO"
typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = (ll)1e9;
const ll INFLL = (ll)1e18+1;
const double PI = acos(-1.0);
/*
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const string dir = "DRUL";
*/
int N,P;
struct mint {
    long long x; // typedef long long long long;
    mint(long long _x=0):x((_x%P+P)%P){}
    mint operator-() const { return mint(-x);}
    mint& operator+=(const mint a) {
        if ((x += a.x) >= P) x -= P;
        return *this;
    }
    mint& operator-=(const mint a) {
        if ((x += P-a.x) >= P) x -= P;
        return *this;
    }
    mint& operator*=(const mint a) {
        (x *= a.x) %= P;
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
    // for prime P
    mint inv() const {
        return modpow(P-2);
    }
    mint& operator/=(const mint a) {
        return (*this) *= a.inv();
    }
    mint operator/(const mint a) const {
        mint res(*this);
        return res/=a;
    }
};
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    cin>>N>>P;
    string S;
    cin>>S;
    if(10 % P == 0){//2 or 5
        ll ans = 0;
        rep(r,N){
            if ((S[r] - '0') % P == 0){
                ans += r+1;
            }
        }
        cout<<ans<<endl;
        return 0;
    }
    vector<mint> cumsum(N+1, 0);
    rep(i,N){
        cumsum[i+1] = cumsum[i] + mint(10).modpow(N-1-i) * (S[i] - '0');
    }
    vector<int> cnt(P,0);
    ll ans = 0;
    rep(i,N+1){
        ans += cnt[cumsum[i].x];
        cnt[cumsum[i].x]++;
    }
    cout<<ans<<endl;
}