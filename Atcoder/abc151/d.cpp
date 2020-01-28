#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define bit(k) (1LL<<(k))
typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = 1e9;
const ll INFLL = 1e18;
const ll MOD = 1e9+7;
const double PI = acos(-1.0);

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

int H,W;
char S[25][25];
/*------------------------------------/
for library*/
bool IsIn(int x,int y){
    return 0<=x&&x<H&&0<=y&&y<W;
}
/*------------------------------------*/
int d[25][25][25][25];
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    
    cin>>H>>W;
    rep(i,H)rep(j,W){
        cin>>S[i][j];
    }
    int ans = 0;
    rep(sx,H)rep(sy,W)rep(i,H)rep(j,W){
        d[sx][sy][i][j] = -1;
        if(S[sx][sy] == '#')continue;
        if(sx == i && sy == j)d[sx][sy][i][j] = 0;
    }
    rep(sx,H)rep(sy,W){
        if(S[sx][sy] == '#')continue;
        queue<pair<int,int>> q;
        q.push({sx,sy});
        while(!q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            rep(i,4){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(!IsIn(nx,ny))continue;
                if(d[sx][sy][nx][ny] != -1)continue;
                if(S[nx][ny] == '#')continue;
                d[sx][sy][nx][ny] = d[sx][sy][x][y]+1;
                q.push({nx,ny});
            }
        }
    }
    rep(sx,H)rep(sy,W)rep(i,H)rep(j,W){
        chmax(ans, d[sx][sy][i][j]);
    }
    cout<<ans<<endl;
}