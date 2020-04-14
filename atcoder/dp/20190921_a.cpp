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
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;cin>>N;
    vector<ll> h(N);
    rep(i,N)cin>>h[i];
    ll dp[N];
    rep(i,N+1)dp[i] = INF;
    dp[0] = 0;
    rep(i,N){
        if(i+1<N){
            dp[i+1] = min(dp[i+1], dp[i] + abs(h[i+1]-h[i]));
        }
        if(i+2<N){
            dp[i+2] = min(dp[i+2], dp[i] + abs(h[i+2]-h[i]));
        }
    }
    cout<<dp[N-1]<<endl;
}