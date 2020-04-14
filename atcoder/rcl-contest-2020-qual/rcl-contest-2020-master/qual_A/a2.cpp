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

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

/*------------------------------------/
for library*/
int N,W,K,V;
int c[1111], v[1111];

constexpr double TL = 1.95;
constexpr ll CYCLES_PER_SEC = 2800000000;
struct Timer {
  ll start;
 
  Timer() { reset(); }
 
  void reset() { start = getCycle(); }
 
  inline double get() { return (double) (getCycle() - start) / CYCLES_PER_SEC; }
 
  inline ll getCycle() {
    unsigned low, high;
    __asm__ volatile ("rdtsc" : "=a" (low), "=d" (high));
    return ((ll) low) | ((ll) high << 32);
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
class Status{
public:
    //行数の最小値
    int H = INF;
    //列数
    int W;
    vector<vector<int>> board;
    vector<int> ans;
    //scores[i]: i行目のscore
    vector<int> scores;
    int score = 0;
    Status(int _W):W(_W){
        board.resize(W);
    }
    void Iniset(){
        rep(i,N){
            ans.push_back(i % W);
            board[i % W].push_back(i);
        }
        rep(i,W){
            chmin(H, (int)board[i].size());
        }
        scores.resize(H,0);
        CalcScore();
    }
    void CalcScore(){
        //ある行について
        scores.assign(H,0);
        score = 0;
        rep(i,H){
            int vv[K] = {0};
            rep(j,W){
                int color = c[board[j][i]];
                int value = v[board[j][i]];
                vv[color] += value;
            }
            rep(k,K){
                chmax(scores[i], vv[k]);
            }
            score += scores[i];
        }
    }

    void Setboard(){
        board.assign(W, vector<int>(0));
        rep(i,N){
            board[ans[i]].push_back(i);
        }
    }
    void debug(){
        cerr<<"(H,W): "<<H<<" "<<W<<endl;
        rep(i,W){
            print(board[i]);
        }
        print(scores);
        cerr<<"score: "<<score<<endl;
    }
};
/*------------------------------------*/

void input(){
    cin>>N>>W>>K>>V;
    rep(i,N){
        cin>>c[i]>>v[i];
    }
}

void simulate(){
    Timer timer;
    timer.reset();

    Status status(W);
    status.Iniset();
    //status.debug();
    int cnt = 0;
    while(1){
        auto now_time = timer.get();
        if(now_time >= TL) break;
        Status status2 = status;
        int idx1 = XorShift() % N;
        int idx2 = XorShift() % N;
        if(idx1 == idx2) continue;
        swap(status.ans[idx1], status.ans[idx2]);
        status2.Setboard();
        status2.CalcScore();
        /*
        if(cnt % 100000 == 0){
            status2.debug();
            cerr<<status.score<<" "<<status2.score<<endl;
        }*/
        if(status.score < status2.score){
            status = status2;
        }
        cnt++;
    }
    //status.debug();
    rep(i,N){
        cout<<status.ans[i]<<endl;
    }
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    input();
    simulate();
}