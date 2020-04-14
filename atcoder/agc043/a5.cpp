#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
typedef long long ll;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const ll INFLL = (ll)1e18+1;

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

int H, W;
bool IsIn(int x,int y){
    return 0<=x&&x<H&&0<=y&&y<W;
}
ll dp[110][110];
int main() {

    cin >> H >> W;
    vector<string> A(H);
    rep(i,H)cin >> A[i];
    rep(i,H)rep(j,W)dp[i][j] = INFLL;
    dp[0][0] = (A[0][0] == '#' ? 1:0);
    rep(i,H)rep(j,W){
        rep(k,2){
            int ni = i + dx[k];
            int nj = j + dy[k];
            if(!IsIn(ni, nj))continue;
            int cost = 0;
            if(A[i][j] == '.' && A[ni][nj] == '#')cost++;
            chmin(dp[ni][nj], dp[i][j] + cost);
        }
    }
    cout << dp[H-1][W-1] << endl;
}