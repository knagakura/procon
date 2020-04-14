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
};

mint dp[2020][2020];
mint sum[2020][2020];
int N,M;
void debug(){
    cerr<<"dp"<<endl;
    rep(i,N+1){
        rep(j,M+1){
        cerr<<dp[i][j].x<<" ";
        }
        cerr<<endl;
    }
    cerr<<endl;

    cerr<<"sum"<<endl;
    rep(i,N+1){
        rep(j,M+1){
        cerr<<sum[i][j].x<<" ";
        }
        cerr<<endl;
    }
    cerr<<endl;
}
//dp[i][j]: Sからi文字、Tからj文字使ったときの部分列の数
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    cin>>N>>M;
    vector<ll> S(N);
    rep(i,N)cin>>S[i];
    vector<ll> T(M);
    rep(i,M)cin>>T[i];

    rep(i,N+1)rep(j,M+1){
        dp[i][j] = 0;
        sum[i][j] = 0;
    }
    dp[0][0] = 1;
    rep(i,N)rep(j,M){
        if(S[i] == T[j]){
            dp[i+1][j+1] = sum[i][j] + 1;
        }
        else{
            dp[i+1][j+1] = 0;
        }
        sum[i+1][j+1] = dp[i+1][j+1] + sum[i][j+1] + sum[i+1][j] - sum[i][j];
    }

    mint ans = 0;
    rep(i,N+1)rep(j,N+1){
        ans += dp[i][j];
    }
    cout<<ans.x<<endl;
}