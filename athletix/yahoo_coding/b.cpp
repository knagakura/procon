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

/*------------------------------------/
for library*/
int N,M;
vector<string> a0;

int a[232][232];
int h[232][232];
bool visited[232][232];
vector<int> wall_min;
void debug(){
    rep(i,N){
        rep(j,M){
            cerr<<a[i][j]<<" ";
        }
        cerr<<endl;
    }cerr<<endl;
    rep(i,N){
        rep(j,M){
            if(h[i][j] == -1)cerr<<"#"<<" ";
            else cerr<<h[i][j]<<" ";
        }
        cerr<<endl;
    }
    cerr<<endl;
}
bool IsIn(int x,int y){
    return 0<=x&&x<N&&0<=y&&y<M;
}
/*------------------------------------*/


bool is_haji(int i, int j){
    return i == 0 || j == 0 || i == N-1 || j == M-1;
}
void dfs_from_haji(int x, int y){
    visited[x][y] = true;
    rep(i,4){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(visited[nx][ny])continue;
        if(is_haji(nx, ny))continue;
        if(a[x][y] <= a[nx][ny]){
            h[nx][ny] = -1;
            dfs_from_haji(nx, ny);
        }
    }
}

void dfs_from_kubomi(int x, int y, int id){
    cerr<<x<<" "<<y<<endl;
    h[x][y] = id;
    visited[x][y] = true;
    //壁チェック
    rep(i,4){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(!IsIn(nx, ny))continue;
        //壁だったら
        if(h[nx][ny] == -1){
            cerr<<"壁"<<a[nx][ny]<<endl;
            chmin(wall_min[id], a[nx][ny]);
        }
    }
    rep(i,4){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(!IsIn(nx,ny))continue;
        if(visited[nx][ny])continue;
        if(h[nx][ny] == -1)continue;
        dfs_from_kubomi(nx, ny, id);
    }
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    cin>>N>>M;
    a0.resize(N);
    wall_min.assign(N * M, INF);
    rep(i,N)cin>>a0[i];
    rep(i,N)rep(j,M){
        a[i][j] = a0[i][j] - '0';
        visited[i][j] = false;
        h[i][j] = 0;
    }
    //端から溢れるところを全探索
    //溢れるところは-1
    
    rep(i,N)rep(j,M){
        if(is_haji(i,j)){
            h[i][j] = -1;
            dfs_from_haji(i,j);
        }
    }
    debug();

    //初期化
    rep(i,N)rep(j,M){
        visited[i][j] = false;
    }
    rep(i,N)rep(j,M){
        if(h[i][j] != -1){
            int cnt = 0;
            rep(k,4){
                int nx = i + dx[k];
                int ny = j + dy[k];
                if(is_haji(nx, ny))continue;
                if(a[i][j] < a[nx][ny]){
                    cnt++;
                }
            }
            if(cnt == 4){
                rep(k,4){
                    int nx = i + dx[k];
                    int ny = j + dy[k];
                    h[nx][ny] = -1;
                }
            }
        }
    }
    //くぼみから全探索
    //周りをすべて網羅して、最小値だけ
    int kubomi_id = 0;
    rep(i,N)rep(j,M){
        if((h[i][j] != -1)&&!(visited[i][j])){
            cerr<<"start from: "<<i<<" "<<j<<endl;
            dfs_from_kubomi(i, j, kubomi_id);
            kubomi_id++;
        }
    }
    debug();
    print(wall_min);
    ll ans = 0;
    rep(i,N)rep(j,M){
        if(h[i][j] >= 0){
            ans += wall_min[h[i][j]] - a[i][j];
        }
    }
    cout<<ans<<endl;
}