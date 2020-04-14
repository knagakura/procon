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
ll dp[2020][2020];
int N,H;
void debug(){
    rep(i,N+1){
        rep(j,H){
            if(dp[i][j] == -1)cerr<<'.'<<" ";
            else cerr<<dp[i][j]<<" ";
        }
        cerr<<endl;
    }
    cerr<<endl;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int l,r;
    cin >> N >> H;
    cin >> l >> r;
    vector<int> a(N);
    rep(i,N)cin>>a[i];
    //print(a);

    //dp[i][j]: i回目の睡眠の後、j時に何回good sleepをしているか
    //dp初期化
    rep(i,N+1)rep(j,H){
        dp[i][j] = -1;
    }
    dp[0][0] = 0;
    rep(i,N)rep(j,H){
        if(dp[i][j] == -1)continue;
        rep(k,2){
            int nxt = (j + a[i] - k) % H;
            if(l <= nxt && nxt <= r ){
                chmax(dp[i+1][nxt], dp[i][j] + 1);
            }
            else{
                chmax(dp[i+1][nxt], dp[i][j]);
            }
        }
    }
    //debug();
    ll ans = -1;
    rep(i,H)chmax(ans, dp[N][i]);
    cout << ans <<endl;
}