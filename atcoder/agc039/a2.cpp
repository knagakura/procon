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
ll dp[1000][30] = {};
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S;ll K;
    cin>>S>>K;
    int N = S.size();
    rep(j,26){
        dp[0][j] = 1;
    }
    dp[0][S[0]-'a'] = 0;
    rep1(i,N+1)rep(j,26){
        dp[i][j] = (ll)INF;
    }
    //jが遷移前,kが遷移後
    rep(i,N-1)rep(j,26)rep(k,26){
        if(j == k)continue;
        ll cost = 1;
        if(k == S[i+1]-'a'){
            cost = 0;
        }
        dp[i+1][k] = min(dp[i+1][k], dp[i][j] + cost);
    }
    ll ans = INF;
    rep(j,26){
        if(j == S[0]-'a')continue;
        ans = min(ans, dp[N-1][j]);
    }
    ll ans1 = dp[N-1][S[0]-'a'] * K + K - 1;
    ans = min(ans * K, ans1);
    if(N==1){
        ans = K/2;
    }
    bool AllSame = true;
    rep(i,N-1){
        if(S[i]==S[i+1])continue;
        else AllSame = false;
    }
    if(AllSame){
        ans = (ll)N * K / 2;
    }
    cout<<ans<<endl;
}
