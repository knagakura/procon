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
ll N,x;
ll a[2320];

//k回回すとき、
//f[i][k] = min({a[i-k] ~ a[i])
//f[i][k] = min(f[i][k-1], a[i-k])
ll f[2320][2320];
int main() {
    cin>>N>>x;
    rep(i,N)cin>>a[i];
    //k回回すとする
    ll ans = 0;
    //k = 0回のとき
    rep(i,N)ans += a[i];

    rep(i,N)f[i][0] = a[i];
    rep1(k,N){
        ll tmp = k * x;
        rep(i,N){
            f[i][k] = min(f[i][k-1], a[(i-k+N) % N]);
            tmp += f[i][k];
        }
        chmin(ans, tmp);
    }
    cout<<ans<<endl;
}