#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)

typedef long long ll;
const int dx[2] = {1, 0};
const int dy[2] = {0, 1};

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = 1e9;

int T[123][123] = {};
ll Cost[123][123] =  {};
int H,W,C;

bool IsIn(int x,int y){
    return 0<=x&&x<H&&0<=y&&y<W;
}
int main() {
    cin>>H>>W>>C;
    rep(i,H)rep(j,W){
        cin>>T[i][j];
        Cost[i][j] = INF;
    }
    Cost[0][0] = 0;
    queue<pair<int,int>> Q;
    Q.push({0,0});
    ll cnt = 1;
    while(!Q.empty()){
        auto p =  Q.front();
        int x = p.first;
        int y = p.second;
        Q.pop();
        rep(i,2){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(!IsIn(nx,ny))continue;
            if(T[nx][ny]==1){
                //chmin(Cost[nx][ny], Cost[x][y] + C);
                Cost[nx][ny] = min(Cost[nx][ny], Cost[x][y] + C);
            }
            else{
                Cost[nx][ny] = min(Cost[nx][ny], Cost[x][y]);
                //chmin(Cost[nx][ny], Cost[x][y]);
            }
            Q.push({nx,ny});
            cnt++;
        }
    }
    cerr<<cnt<<endl;
    cout<<Cost[H-1][W-1]<<endl;
}