#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }

typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = 1e9;
const ll INFLL = 1e18;
const ll MOD = 1e9+7;

const double PI = acos(-1.0);

//右、上、左、下
const char direction[4] = {'R','D','L','U'};
const char revdireciton[4] = {'L','U','R','D'};
//右、上、左、下
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};
//左、下、右、上
//const int prex[4] = {-1,0,1,0};
//const int prey[4] = {0,-1,0,1};

int N,M,B;
int gy,gx;
char Field[45][45];
bool visited[45][45];
bool ANNAIed[45][45];
char Robot[45][45];
vector<pair<pair<int,int>, char>> r;
vector<pair<pair<int,int>, char>> ans;


//初期化
void init(){
    rep(i,N)rep(j,N){
        Field[i][j] = '.';
        visited[i][j] = false;
        ANNAIed[i][j] = false;
        Robot[i][j] = '.';
    }
    ANNAIed[gy][gx] = true;
}

//入力
void input(){
    cin>>N>>M>>B;
    cin>>gy>>gx;
    init();
    Field[gy][gx] = 'G';
    //ロボット
    rep(i,M){
        int ry,rx;char c;
        cin>>ry>>rx>>c;
        Robot[ry][rx] = c;
    }
    //ブロック
    rep(i,B){
        int by,bx;
        cin>>by>>bx;
        Field[by][bx] = '#';
    }
}
//フィールドからはみ出す場合
int GetNext(int now,int d){
    if(now == N-1&&d == 1){
        return 0;
    }
    else if(now == 0&&d == -1){
        return N-1;
    }
    else{
        return now + d;
    }
}
//ある個体に当たるまで歩き続ける
void dfs(int y, int x, int dir){
    if(visited[y][x])return;
    visited[y][x] = true;
    //一個下がる
    int prey = GetNext(y,-dy[dir]);
    int prex = GetNext(x,-dx[dir]);
    //ロボットマスだったら（向きがわかる）
    if(Robot[y][x] != '.'){
        if(direction[dir] == Robot[y][x]){
            return;
        }
        else{
            if(!ANNAIed[prey][prex]){
            ans.push_back({{prey,prex},revdireciton[dir]});
            }
        }
        return;
    }
    //cerr<<y<<" "<<x<<endl;
    //壁に当たったら
    if(Field[y][x] == '#'){
        visited[prey][prex] = false;
        //逆方向に歩かせるように案内を入れる
        //Field[prey][prex] = revdireciton[dir];
        if(!ANNAIed[prey][prex]){
            ans.push_back({{prey,prex},revdireciton[dir]});
        }
        ANNAIed[prey][prex] = true;
        //横方向の移動だったら
        if(dir%2 ==0){
            //縦に変える
            dfs(prey, prex, 1);
            dfs(prey, prex, 3);
            //縦だったら
        }else{
            //横に変える
            dfs(prey, prex, 0);
            dfs(prey, prex, 2);
        }
    }
    /*
    //いった先で方向案内があったら
    else if(Field[y][x] == 'R'){
        dir = 0;
    }
    else if(Field[y][x] == 'U'){
        dir = 1;
    }
    else if(Field[y][x] == 'L'){
        dir = 2;
    }
    else if(Field[y][x] == 'D'){
        dir = 3;
    }
    */
    //空きマスなら
    else{
        int ny = GetNext(y,dy[dir]);
        int nx = GetNext(x,dx[dir]);
        dfs(ny,nx,dir);
    }

}


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    input();
    //4方向にスタート
    rep(dir, 4){
        int ny = GetNext(gy,dir);
        int nx = GetNext(gx,dir);
        dfs(ny,nx,dir);
    }
    int NN = ans.size();
    cout<<NN<<endl;
    rep(i,NN){
        cout<<ans[i].first.first<<" "<<ans[i].first.second<<" "<<ans[i].second<<endl;
    }
}