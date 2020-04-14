#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }

typedef long long ll;
typedef pair<ll,pair<int,int>> PP;

const int MOD = 1e9+7;
const int INF = 1e9;

int H,W,T;
vector<string> s;
pair<int, int> start, goal;
ll Graph[15][15];

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

bool FieldIN(int x,int y){
    return 0<=x&&x<H&&0<=y&&y<W;
}
bool check(ll X){
    
    priority_queue<PP, greater<PP>()> Q;
    return true;
}
/*
//到達できるならtrue
bool check(ll X){
    ll dis[15][15];
    rep(i,H)rep(j,W){
        dis[i][j] = -1;
    }
    dis[start.first][start.second] = 0;
    queue<pair<int,int>> que;
    que.push(start);
    while(!que.empty()){
        auto now = que.back();
        que.pop();
        int x = now.first;
        int y = now.second;
        rep(l,4){
            int nx = x + dx[l];
            int ny = y + dy[l];
            if(!FieldIN(nx,ny))continue;
            //未探索なら
            if(dis[nx][ny]==-1){
                que.push({nx,ny});
                if(s[nx][ny] == 'G'||s[nx][ny] == '.'){
                    dis[nx][ny] = dis[x][y] + 1;
                }
                else{
                    dis[nx][ny] = dis[x][y] + X;
                }
            }
            //すでに訪れているなら
            else{
                if(s[nx][ny] == 'G'||s[nx][ny] == '.'){
                    if(dis[nx][ny]>dis[x][y]+1){
                        que.push({nx,ny});
                        dis[nx][ny] = min(dis[nx][ny],dis[x][y] + 1);
                    }
                }
                else{
                    if(dis[nx][ny]>dis[x][y]+X){
                        que.push({nx,ny});
                        dis[nx][ny] = min(dis[nx][ny],dis[x][y] + X);
                    }
                }
            }
        }
    }
    ll GoalTime = dis[goal.first][goal.second];
    cerr<<X<<" "<<GoalTime<<" "<<(GoalTime<=T)<<endl;
    return GoalTime <= T;
}
*/

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    cin>>H>>W>>T;
    s.resize(H);
    rep(i,H)cin>>s[i];
    rep(i,H)rep(j,W){
        if(s[i][j] == 'S'){
            start  = {i,j};
        }
        if(s[i][j] ==  'G'){
            goal = {i,j};
        }
    }
    rep(i,H)rep(j,W){

    }
    ll ok = 1, ng = 1e14;
    while(ng-ok>1){
        ll mid = (ok+ng)/2;
        if(true){
            ok = mid;
        }
        else{
            ng = mid;
        }
    }
    cout<<ok<<endl;
}