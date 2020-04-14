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
ll dp[105][123456];
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,W;
    cin>>N>>W;
    vector<ll> w(N),v(N);
    rep(i,N)cin>>w[i]>>v[i];
    rep(i,N)rep(j,W+1){
        dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
        if(j + w[i] > W)continue;
        dp[i+1][j + w[i]] = max(dp[i+1][j + w[i]], dp[i][j] + v[i]);
    }
    ll ans = dp[N][W];
    cout<<ans<<endl;
}