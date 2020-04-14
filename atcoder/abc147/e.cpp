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
int H,W;
int A[100][100];
int B[100][100];
bool dp[100][100][10000];
void debug(){
    rep(i,H+1){
        rep(j,W+1){
        cerr<<dp[i][j][0]<<" ";
        }
        cerr<<endl;
    }
    cerr<<endl;
    cerr<<endl;
    rep(i,H+1){
        rep(j,W+1){
        cerr<<dp[i][j][1]<<" ";
        }
        cerr<<endl;
    }
    cerr<<endl;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    cin>>H>>W;
    rep(i,H)rep(j,W){
        cin>>A[i][j];
    }
    rep(i,H)rep(j,W){
        cin>>B[i][j];
    }
    rep(i,H)rep(j,W)rep(k,10000){
        dp[i][j][k] = false;
    }
    dp[0][0][abs(A[0][0] - B[0][0])] = true;
    rep(i,H)rep(j,W)rep(k, 10000){
        if(dp[i][j][k]){
            dp[i+1][j][    k + abs(A[i+1][j] - B[i+1][j]) ] = true;
            dp[i+1][j][abs(k - abs(A[i+1][j] - B[i+1][j]))] = true;
            dp[i][j+1][    k + abs(A[i][j+1] - B[i][j+1]) ] = true;
            dp[i][j+1][abs(k - abs(A[i][j+1] - B[i][j+1]))] = true;
        }
    }
    /*
    rep(i,H+1)rep(j,W+1){
        cerr<<"("<<i<<", "<<j<<")"<<endl;
        rep(k, 6500){
            if(dp[i][j][k]){
                cerr<<k<<" ";
            }
        }
        cerr<<endl;
    }
    */
    ll ans = -1;
    rep(i,10000){
        if(dp[H-1][W-1][i]){
            ans = i;
            break;
        }
    }
    if(ans == -1)cerr<<"what!?"<<endl;
    cout<<ans<<endl;
}