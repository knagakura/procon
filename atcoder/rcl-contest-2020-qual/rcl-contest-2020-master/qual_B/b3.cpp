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
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}

const int INF = 1e9;
//R,D,L,U
const int dx[8] = {0, 1, 0, -1, 1, -1, -1, 1};
const int dy[8] = {1, 0, -1, 0, 1, 1, -1, -1};
char drc[4] = {'R', 'D', 'L', 'U'};

/*------------------------------------/
for library*/

class Status{
  int N,M;
public:
  int A[50][50];
  int board[50][50];
  int shazo[50][50];
  int score = 0;
  int coll[4] = {0, 2, 3, 1};
  vector<int> x, y, dirs;
  int count = 0;
  int swirl_count = 0;
  Status(int _N, int _M):N(_N), M(_M){
    x.assign(M, -1);
    y.assign(M, -1);
    dirs.assign(M, -1);
    Fill(board, -1);
    board[0][0] = 0;
    board[0][N-1] = 1;
    board[N-1][0] = 2;
    board[N-1][N-1] = 3;
  }
  void Ainput(){
    rep(i,N)rep(j,N){
      cin>>A[i][j];
    }
  }
  void Paint(int color, int sx, int sy, int dir){
    count++;
    if(color!= board[sx][sy]){
        cerr<<"error: "<< sx<<", "<<sy<<" is not "<<color<<" color !!"<<endl;
        return;
    }
    rep1(i, 6){
      int nx = sx + dx[dir] * i;
      int ny = sy + dy[dir] * i;
      if(!isin(nx, ny))continue;
      board[nx][ny] = color;
    }
  }
  //四隅から正方形っぽいのを作る
  void BoardInit(){
    //色iについて
    rep(i,4){
      rotate();
    }
  }
  //渦巻き
  void MakeSwirl(bool rotation = false){
      rep(i,4){
          
          int right[4] = {0,1,2,3};
          int left[4] = {1,0,3,2};
          int ax=0,ay=0;
          count = -1;
          if(rotation){
            rep(l, 4)right[l] = left[l];
          }

          //->
          rep(j, 9){
              swirl_count++;
              ax = 0;
              ay = 5 * j;
              if(rotation)swap(ax,ay);
              Paint(coll[i],  ax,  ay, right[0]);
              setxyz(i, count * 4 + coll[i],
              ax, ay, right[0]);
          }
          //↓
          rep(j, 8){
            swirl_count++;
            ax = j * 5;
            ay = 45;
            if(rotation)swap(ax, ay);
            Paint(coll[i], ax, ay, right[1]);
            setxyz(i, count * 4 + coll[i], 
            ax, ay, right[1]);
          }
          //<-
          rep(j, 6){
              swirl_count++;
              ax = 40;
              ay = 45 - j * 5;
              if(rotation)swap(ax, ay);
              Paint(coll[i], 
              ax, ay, right[2]);
              setxyz(i, count * 4 + coll[i], 
              ax, ay, right[2]);
          }
          //↑
          rep(j, 4){
              swirl_count++;
              ax = 40 - j * 5;
              ay = 15;
              if(rotation)swap(ax, ay);
              Paint(coll[i], 
              ax, ay, right[3]);
              setxyz(i, count * 4 + coll[i], 
              ax, ay, right[3]);
          }
          rep(j,1){
            swirl_count++;
            ax = 20;
            ay = 15 + j * 5;
            if(rotation)swap(ax, ay);
            Paint(coll[i],
            ax, ay, right[0]);
            setxyz(i, count  * 4 + coll[i],
            ax, ay, right[0]);
          }
          //debug();
          rotate();
      }
  }
  int check_score(int color, int sx, int sy, int dir){
    if(color!= board[sx][sy])return -10;
    int res = 0;
    rep1(i, 6){
      int nx = sx + dx[dir] * i;
      int ny = sy + dy[dir] * i;
      if(!isin(nx, ny))continue;
      //一致していない
      if(board[nx][ny] != A[nx][ny]){
          //変更することで一致するなら
          if(color == A[nx][ny])res += 1;
          //変更しても一致しない
          else res -= 0;
      }
      //すでに一致
      else{
          //変更しても変わらない
          if(color == A[nx][ny])res += 0;
          //変更して崩してしまう
          else res -= 1;
      }
    }
    return res;
  }
  void greedy_paint(){
      for(int i = swirl_count; i < M; i++){
          int color = i % 4;
          int tmpscore = 0;
          int resx = -1, resy = -1, resdir = -1;
          rep(h, N)rep(w, N){
              rep(dir, 4){
                  if(board[h][w] == color && chmax(tmpscore, check_score(color, h, w, dir))){
                      resx = h;
                      resy = w;
                      resdir = dir;
                  }
              }
          }
          //cerr<<resx<<" "<<resy<<" "<<resdir<<endl;
          if(resx == -1)continue;
          Paint(color, resx, resy, resdir);
          setxyz(0, i, resx, resy, resdir);
      }
  }
  void setxyz(int cnt, int idx, int ax, int ay, int dir){
    auto p = rerotate(cnt, ax, ay);
    ax = p.first;
    ay = p.second;
    dir = (dir + 4 - cnt) % 4;
    x[idx] = ax;
    y[idx] = ay;
    dirs[idx] = dir;
  }
  void output(){
    rep(i,M){
      if(x[i] == -1)cout<<-1<<endl;
      else cout<<x[i]<<" "<<y[i]<<" "<<drc[dirs[i]]<<endl;
    }
  }
  void debug(){
    rep(i,N){
      rep(j,N){
        if(board[i][j] == -1){
          cerr<<"."<<" ";
        }
        else cerr<<board[i][j]<<" ";
      }
      cerr<<endl;
    }
    cerr<<endl;
  }
  bool isin(int ax,int ay){
    return 0<=ax&&ax<50&&0<=ay&&ay<50;
  }
  void rotate(){
    int nxt[50][50] = {0};
    rep(i,N)rep(j,N) nxt[j][N-i-1]=board[i][j];
		rep(i,N)rep(j,N) board[i][j]=nxt[i][j];
  }
  pair<int, int> rerotate(int cnt, int ax, int ay){
    int tmpx = ax;
    int tmpy = ay;
    rep(_, cnt){
      tmpx = N - 1 - ay;
      tmpy = ax;
      ax = tmpx;
      ay = tmpy;
    }
    return make_pair(ax, ay);
  }
  void Calc_score(){
      rep(i,N)rep(j,N){
          if(A[i][j] == board[i][j])score++;
      }
  }
};
struct Timer {
  chrono::high_resolution_clock::time_point st;

  Timer() { reset(); }

  void reset() {
    st = chrono::high_resolution_clock::now();
  }

  chrono::milliseconds::rep elapsed() {
    auto ed = chrono::high_resolution_clock::now();
    return chrono::duration_cast< chrono::milliseconds >(ed - st).count();
  }
};
uint32_t XorShift(void) {
	static uint32_t x = 123456789;
	static uint32_t y = 362436069;
	static uint32_t z = 521288629;
	static uint32_t w = 88675123;
	uint32_t t;
 
	t = x ^ (x << 11);
	x = y; y = z; z = w;
	return w = (w ^ (w >> 19)) ^ (t ^ (t >> 8));
}
/*------------------------------------*/

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N,M;
    cin>>N>>M;
    Status ans(N,M);
    ans.Ainput();

    /* simulation */

    ans.MakeSwirl();
    ans.debug();
    //ans.debug();
    ans.greedy_paint();
    ans.Calc_score();
    /* ans2 */
    Status ans2(N,M);

    rep(i,N)rep(j,N){
      ans2.A[i][j] = ans.A[i][j];
    }
    ans2.MakeSwirl(true);
    ans2.debug();
    ans2.greedy_paint();
    ans2.Calc_score();
    
    
    cerr<<ans.score<<" "<<ans2.score<<endl;
    if(ans.score < ans2.score){
      ans2.output();
    }
    else{
      ans.output();
    }

    /*
    print(ans.x);
    print(ans.y);
    print(ans.dirs);*/
    //ans.debug();
}