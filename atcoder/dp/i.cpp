#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }

using P = pair<int, int>;
typedef long long ll;

const int MOD = 1e9+7;
const int INF = 1e9;
double dp[3005][3005] = {};

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin>>N;
    vector<double> p(N);
    rep(i,N)cin>>p[i];

    dp[0][0] = 1;
    rep(i,N)rep(j,N){
        dp[i+1][j+1] += dp[i][j] * p[i];
        dp[i+1][j] += dp[i][j] * (double)(1-p[i]);
    }
    double ans = 0;
    for(int j = (N+1)/2; j <= N; ++j){
        ans += dp[N][j];
    }
    cout<<setprecision(10)<<ans<<endl;
}