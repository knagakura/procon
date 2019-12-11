#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
typedef long long ll;
ll dp[1234567];
ll digit_sum(ll X){
    ll res = 0;
    string S = to_string(X);
    rep(i,(int)S.size()){
        res += S[i]-'0';
    }
    return res;
}
int main() {
    int N;
    cin>>N;
    rep1(i,N+1){
        dp[i] = 1;
    }
    rep1(i,N){
        dp[i + digit_sum(i)] += dp[i];
    }
    cout<<dp[N]<<endl;
}
