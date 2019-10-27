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
int A[15][15];
int N,M,K;

int dp[15][550];
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    cin>>N>>M>>K;
    rep(i,N)rep(j,M){
        cin>>A[i][j];
    }
    dp[0][0] = 1;
    rep(i,N)rep(j,K){
        if(dp[i][j]){
            rep(k,M){
                if(j+A[i][k]<=K){
                    dp[i+1][j + A[i][k]] = 1;
                }
            }
        }
    }
    int ans = -1;
    rep(j,K+1){
        if(dp[N][j]){
            ans = K-j;
        }
    }
    cout<<ans<<endl;
}