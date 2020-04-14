#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)

typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int H,W;
int c[10][10];
int A[216][216];

int main() {
    cin>>H>>W;
    rep(i,10)rep(j,10){
        cin>>c[i][j];
    }
    rep(i,H)rep(j,W){
        cin>>A[i][j];
    }
    rep(k,10)rep(i,10)rep(j,10){
        chmin(c[i][j], c[i][k] + c[k][j]);
    }
    ll ans = 0;
    rep(i,H)rep(j,W){
        if(A[i][j] == -1)continue;
        ans += c[A[i][j]][1];
    }
    cout<<ans<<endl;
}