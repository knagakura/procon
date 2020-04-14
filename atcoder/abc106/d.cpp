#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)

int G[505][505];
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N,M,Q;
    cin>>N>>M>>Q;
    rep(i,N)rep(j,N){
        G[i][j] = 0;
    }
    vector<int> L(M),R(M),p(Q),q(Q);
    rep(i,M){
        cin>>L[i]>>R[i];
        G[L[i]][R[i]]++;;
    }
    rep(i, Q){
        cin>>p[i]>>q[i];
    }
    rep1(i,N+1)rep1(j,N+1){
        G[i][j] += G[i-1][j];
        G[i][j] += G[i][j-1];
        G[i][j] -= G[i-1][j-1];
    }
    rep(i,Q){
        int ans = G[q[i]][q[i]] - G[p[i]-1][q[i]] - G[q[i]][p[i]-1] + G[p[i]-1][p[i]-1];
        cout<<ans<<endl;
    }
}