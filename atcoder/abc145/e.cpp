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
int N,T;
vector<pair<int,int>> AB;
//i番目の食べ物のなかでT秒以内に食べられる（その注文がT秒以内だったか）
ll dp[3050][12345];
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    cin>>N>>T;
    rep(i,N){
        int a,b;
        cin>>a>>b;
        AB.push_back({a,b});
    }
    sort(all(AB));
    rep(t,8000){
        dp[0][t][0] = 0;
        dp[0][t][1] = 0;
    }
    rep(i,N)rep(t,T+1){
        chmax(dp[i+1][t + AB[i].first][1],dp[i][t][1] + AB[i].second);
        chmax(dp[i+1][t][1],dp[i][t][1]);
    }
    ll ans = 0;
    rep(t,12345){
        chmax(ans, dp[N][t][1]);
    }

    cout<<ans<<endl;
    /*
    rep(i,N+1){
        rep(t,70){
        cerr<<dp[i][t][1]<<" ";
        }
        cerr<<endl;
    }
    */
}