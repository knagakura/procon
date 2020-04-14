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
const ll INFLL = 1e18;
const ll MOD = 1e9+7;
const double PI = acos(-1.0);
//R,D,L,U
const int dx[8] = {0, 1, 1, -1, 1, -1, -1, 1};
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
    if(color!= board[sx][sy])return;
    rep1(i, 6){
      int nx = sx + dx[dir] * i;
      int ny = sy + dy[dir] * i;
      if(!isin(nx, ny))continue;
      board[nx][ny] = color;
    }
  }
  bool isin(int ax,int ay){
    return 0<=ax&&ax<50&&0<=ay&&ay<50;
  }
  //四隅から正方形っぽいのを作る
  void BoardInit(){
    //色iについて
    //
    rep(i,4){
      //mod 4のjdx
      auto p = rerotate(i,0,0);
      //cerr<<p.first<<" "<<p.second<<endl;
      int cnt = 0;
      rep(j,5){
        int nx =dx[0] * 5 * j;
        int ny =dy[0] * 5 * j;
        Paint(coll[i], nx , ny, 0);
        int idx = coll[i] + 4 * cnt;
        setxyz(i, idx, nx, ny, 0);
        cnt++;
      }
      rep(j,5){
        int nx = dx[1] * 5 * j;
        int ny = dy[1] * 5 * j;
        Paint(coll[i],nx,ny,1);
        int idx = coll[i] + 4 * cnt;
        setxyz(i, idx, nx, ny, 1);
        cnt++;
      }
      //debug();
      for(int j = 1;j <= 20;j++){
        rep(k,5){
          int nx = j;
          int ny = 0 + 5 * k;
          Paint(coll[i], nx , ny, 0);
          int idx = coll[i] + 4 * cnt;
          setxyz(i, idx, nx, ny, 0);
          cnt++;
        }
      }
      rotate();
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

    ans.BoardInit();
    ans.output();
    /*
    print(ans.x);
    print(ans.y);
    print(ans.dirs);*/
    //ans.debug();
}