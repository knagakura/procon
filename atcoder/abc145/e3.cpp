#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const ll INFLL = 1e18;
int main() {
    int N,T;
    cin>>N>>T;
    vector<ll> A(N),B(N);
    rep(i,N){
        cin>>A[i]>>B[i];
    }
    vector<vector<ll>> dp1(N+2,vector<ll>(T,-INFLL)),dp2(N+2,vector<ll>(T,-INFLL));
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
    for (int i = N-1; i >= 0; --i){
        rep(t,T){
        chmax(dp2[i+1][t], dp2[i+2][t]);
        if(t + A[i] < T){
                chmax(dp2[i+1][t + A[i]],dp2[i+2][t] + B[i]);
            }
        }
    }
    ll ans = 0;
    rep1(i,N+1){
        rep(t,T){
            chmax(ans, dp1[i-1][t] + dp2[i+1][T-1-t] + B[i-1]);
        }
    }
    cout<<ans<<endl;
}