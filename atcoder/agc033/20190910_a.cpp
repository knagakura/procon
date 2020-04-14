#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()		 //sort(all(vi S)) sort(all(string S))
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }

using P = pair<int, int>;		//P.first, P.second
typedef long long ll;
typedef vector<int> vi;
typedef set<int> seti;
typedef vector<string> vs;

const int MOD = 1e9+7;
const int INF = 1e9;
char A[1005][1005];
int H,W;
bool IsIn(int x, int y){
    return 0<=x&&x<H&&0<=y&&y<W;
}
int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};
int dist[1005][1005];
int main() {
    cin>>H>>W;
    queue<pair<int,int>> Q;
    rep(i,H)rep(j,W){
        cin>>A[i][j];
        if(A[i][j]=='#'){
            Q.push({i,j});
            dist[i][j] = 0;
        }
        else{
            dist[i][j] = -1;
        }
    }
    //BFS
    while(!Q.empty()){
        auto p = Q.front();
        Q.pop();
        int x = p.first;int y = p.second;
        rep(i,4)rep(j,4){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(!(IsIn(nx,ny))||dist[nx][ny]!=-1){
                continue;
            }
            dist[nx][ny] = dist[x][y]+1;
            Q.push({nx,ny});
        }
    }
    int ans = 0;
    rep(i,H)rep(j,W){
        ans = max(ans, dist[i][j]);
    }
    cout<<ans<<endl;

}