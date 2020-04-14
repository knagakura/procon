#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const ll INFLL = 1e18;
int main() {
    int N,T;
    cin>>N>>T;
    vector<ll> A(N),B(N);
    rep(i,N)cin>>A[i]>>B[i];
    /*
    dp1[i][t]:1~iまでの食べ物でt秒以内に完食して得られる満足度の最大値
    dp2[i][t]:N~iまでの食べ物でt秒以内に完食して得られる満足度の最大値
    => dp1[i-1][t] + dp2[i+1][T-1-t]:i以外の食べ物でT-1秒以内に完食して得られる満足度の最大値
       これにB[i+1]を足せば、OK
    */
    vector<vector<ll>> dp1(N+2,vector<ll>(T,-INFLL));
    vector<vector<ll>> dp2(N+2,vector<ll>(T,-INFLL));
    rep(t,T){
        dp1[0][t] = 0;
        dp2[N+1][t] = 0;
    }
    rep(i,N)rep(t,T){
        chmax(dp1[i+1][t], dp1[i][t]);
        if(t + A[i] < T){
            chmax(dp1[i+1][t+A[i]],dp1[i][t] + B[i]);
        }
    }
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    rep(i,N)rep(t,T){
            chmax(dp2[N+1-i-1][t], dp2[N+1-i][t]);
            if(t + A[i] < T){
                chmax(dp2[N+1-i-1][t + A[i]],dp2[N+1-i][t] + B[i]);
            }
    }
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    ll ans = 0;
    rep(i,N){
        rep(t,T){
            chmax(ans, dp1[i][t] + dp2[i+2][T-1-t] + B[i]);
        }
    }
    cout<<ans<<endl;
}