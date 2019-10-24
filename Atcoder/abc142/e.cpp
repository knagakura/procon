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
ll dp[1005][10000] = {};
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,M;
    cin>>N>>M;
    vector<ll> a(M),b(M);
    vector<vector<ll>> c(M);
    vector<ll> bit(M,0);
    rep(i,M){
        cin>>a[i]>>b[i];
        c[i].resize(b[i]);
        rep(j,b[i]){
            cin>>c[i][j];
            c[i][j]--;
            bit[i] |= (1<<c[i][j]);
        }
    }
    /*
    rep(i,M){
        print(c[i]);
    }
    */
    print(bit);
    rep(i,M+1)rep(j,10000){
        dp[i][j] = INF;
    }
    dp[0][0] = 0;
    rep(i,M)rep(j,10000){
        dp[i+1][j] = min(dp[i+1][j], dp[i][j]);
        dp[i+1][j|bit[i]] = min(dp[i+1][j|bit[i]], dp[i][j] + a[i]);
    }
    int all1 = 0;
    rep(i,N){
        all1 |= (1<<i);
    }
    cerr<<all1<<endl;
    ll ans = dp[M][all1];
    /*
    rep(i,M+1){
        rep(j,all1+1){
            cerr<<dp[i][j]<<" ";
        }
        cerr<<endl;
    }
    */
    if(ans == INF)ans = -1;
    cout<<ans<<endl;

}