#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)

typedef long long ll;
typedef vector<string> vs;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int main() {
    int N;
    cin>>N;
    vector<string> S(N),T(N)/*,A(N),B(N),C(N)*/;
    char A[550][550],B[550][550],C[550][550];
    rep(i,N)cin>>S[i];
    rep(i,N)cin>>T[i];
    rep(i,N)rep(j,N){
        A[j][N-i-1] = S[i][j];
    }
    rep(i,N)rep(j,N){
        B[j][N-i-1] = A[i][j];
    }
    rep(i,N)rep(j,N){
        C[j][N-i-1] = B[i][j];
    }
    int res[4] = {0,1,2,1};
    rep(i,N)rep(j,N){
        if(S[i][j] == T[i][j])continue;
        res[0]++;
    }
    rep(i,N)rep(j,N){
        if(A[i][j] == T[i][j])continue;
        res[1]++;
    }
    rep(i,N)rep(j,N){
        if(B[i][j]==T[i][j])continue;
        res[2]++;
    }
    rep(i,N)rep(j,N){
        if(C[i][j] == T[i][j])continue;
        res[3]++;
    }
    int ans = res[0];
    rep(i,4)chmin(ans, res[i]);
    cerr<<res[0]<<" "<<res[1]<<" "<<res[2]<<" "<<res[3]<<endl;
    cout<<ans<<endl;
}