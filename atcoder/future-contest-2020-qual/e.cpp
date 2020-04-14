#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }

typedef long long ll;
typedef tuple<int, int, char> mytuple;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = 1e9;
const ll INFLL = 1e18;
const ll MOD = 1e9+7;

const double PI = acos(-1.0);



/*-------------------------------------------------------------------------------------------------*/
//右、上、左、下
const char direction[4] = {'R','D','L','U'};
const char revdireciton[4] = {'L','U','R','D'};
//右、上、左、下
const int dy[4] = {0, 1, 0, -1};
const int dx[4] = {1, 0, -1, 0};
//左、下、右、上
//const int prex[4] = {-1,0,1,0};
//const int prey[4] = {0,-1,0,1};

int N,M,B;
int gy,gx;
//ロボット、壁、ゴールの場所をメモ
char Field[45][45];
//ゴールから逆算してどの方向に行けばゴールかの方向を教えてくれる
//ロボットの位置以外代入
char VirtualField[45][45];

bool VisitedInSimulation[45][45];
bool ANNAIed[45][45];
//vector<pair<pair<int,int>, char>> r;
vector<pair<pair<int,int>, char>> ans;
vector<int> RY,RX;
vector<char> C;

set<mytuple> SET;

//初期化
void init(){
    rep(i,N)rep(j,N){
        Field[i][j] = '.';
        VirtualField[i][j] = '.';
        VisitedInSimulation[i][j] = false;
        ANNAIed[i][j] = false;
    }
}

//入力
void input(){
    cin>>N>>M>>B;
    cin>>gy>>gx;
    init();
    Field[gy][gx] = VirtualField[gy][gx] ='G';
    //ロボット
    RY.resize(M);RX.resize(M);C.resize(M);
    rep(i,M){
        cin>>RY[i]>>RX[i]>>C[i];
        Field[RY[i]][RX[i]] = C[i];
    }

    //ブロック
    rep(i,B){
        int by,bx;
        cin>>by>>bx;
        Field[by][bx] = VirtualField[by][bx] = '#';
    }
}

//今の座標と移動先を入力して次の座標をもらう関数
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

void bfs(){
    queue<pair<int,int>> Q;
    Q.push({gy,gx});
    while(!Q.empty()){
        auto p = Q.front();
        Q.pop();
        int y = p.first;
        int x = p.second;
        rep(dir,4){
            int ny = GetNext(y,dy[dir]);
            int nx = GetNext(x,dx[dir]);
            if(VirtualField[ny][nx] == '.'){
            VirtualField[ny][nx] = revdireciton[dir];
            //ans.push_back({{ny,nx},revdireciton[dir]});
            Q.push({ny,nx});
            }
        }
    }
}
//'R','D','L','U'

void Simulation(int ry, int rx, char pre_dir){
    while(ry != gy && rx != gx){
        auto it = SET.find(make_tuple(ry,rx,pre_dir));
        //すでにやったことがあったら
        if(it != SET.end()){
            break;
        }
        SET.insert(make_tuple(ry,rx,pre_dir));
        //VisitedInSimulation[ry][rx] = true;
        if(pre_dir == 'R'){
            ry = GetNext(ry,dy[0]);
            rx = GetNext(rx,dx[0]);
        }
        else if(pre_dir == 'D'){
            ry = GetNext(ry,dy[1]);
            rx = GetNext(rx,dx[1]);
        }
        else if(pre_dir == 'L'){
            ry = GetNext(ry,dy[2]);
            rx = GetNext(rx,dx[2]);
        }
        else if(pre_dir == 'U'){
            ry = GetNext(ry,dy[3]);
            rx = GetNext(rx,dx[3]);
        }
        if(ry == gy&&rx == gx)break;
        if(VirtualField[ry][rx] == '.')break;
        if(pre_dir != VirtualField[ry][rx] && (!ANNAIed[ry][rx])){
            ans.push_back({{ry,rx},VirtualField[ry][rx]});
            ANNAIed[ry][rx] = true;
        }
        pre_dir = VirtualField[ry][rx];
    }
    return;
}

/*
void CERROR(){
    rep(y,N)rep(x,N){
        cerr<<VirtualField[y][x];
        if(x == N-1)cerr<<endl;
        else{
            cerr<<" ";
        }
    }
}
*/
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    input();
    //VirtialFieldを埋める（無駄が多い）
    bfs();
    /*
    その中で真に必要なものだけを抽出するために
    ロボット一つ一つからシミュレーションをする
    */
    rep(i,M){
        Simulation(RY[i],RX[i],C[i]);
    }
    //CERROR();
    int Nans = ans.size();
    cout<<Nans<<endl;
    rep(i,Nans){
        cout<<ans[i].first.first<<" "<<ans[i].first.second<<" "<<ans[i].second<<endl;
    }
    
}