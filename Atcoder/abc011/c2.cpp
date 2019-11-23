#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
typedef long long ll;
int dp[324][150];
int N;
int main() {
    cin>>N;
    vector<bool> ng(301, false);
    rep(i,3){
        int NG; cin>>NG;
        ng[NG] = true;
    }
    rep(i,N)rep(j,110){
        dp[i][j] = -1;
    }
    rep(j,110){
        dp[N][j] = 1;
    }
    for(int i = N; i >= 0;i--){
        for(int j = 0; j < 110; j++){
            if(dp[i][j] == -1)continue;
            if(ng[i])continue;
            rep1(k,4){
                if(i-k < 0)continue;
                if(ng[i-k])continue;
                dp[i-k][j+1] = 1;
            }
        }
    }
    cout<< ((dp[0][100]==1) ? "YES":"NO")<<endl;
}