#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define dump(x) cerr<<#x<<": "<<x<<endl;
#define bit(k) (1LL<<(k))
#define Yes "Yes"
#define No "No"
#define YES "YES"
#define NO "NO"
typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = (ll)1e9;
const ll INFLL = (ll)1e18+1;
const ll MOD = (ll)1e9+7;
const double PI = acos(-1.0);
/*
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const string dir = "DRUL";
*/
const int N = 500;
const int M = 5000;
vector<int> V(N+1,-1);
vector<int> d = {1,2,3,4,5,6};
ll scan_score = 0;
ll score = 0;
int now_idx = 0;
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
constexpr double TL = 1.0;
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

void input(){
    int _;
    cin>>_>>_;
    V[0] = 0;
    V[500] = 5000;
}
void scanning(){
    //N回
    rep(i,N+30){
        rep(j,6){
            cout<<d[j];
            if(j == 5)cout<<endl;
            else cout<<" ";
        }
        int d_out,v_next,next_idx;
        cin>>d_out>>v_next>>next_idx;
        V[next_idx] = v_next;
        scan_score += v_next;
        now_idx = next_idx;
        //change dice first 5 time
        if(i < 5){
            d[5-i] = 1;
        }
        /*
        if(next_idx == 500)cerr<<"GOAL!!!!"<<endl;
        if((i+1) % 100 == 0){
            cerr<<i+1<<"回目"<<endl;
            print(V);
            print(d);
        }
        */
    }
    //print(V);
}

//だいたいVの値が見えるので、0の区間を踏まないようにしたい
//一通りsimulationするのを、時間ギリギリまで繰り返す
void simulate(Timer& timer){
    ll best_score = scan_score;
    //cerr<<"scan_score: "<<scan_score<<endl;
    int base_idx = now_idx;
    for(int i = N+30;i < M;i++){
        base_idx++;
        best_score += V[base_idx];
        base_idx %= N;
        //cerr<<best_score<<" "<<base_idx<<endl;
    }
    //cerr<<"best_score: "<<best_score<<endl;
    //M - (N+30) 回
    int d_true[M+1][6] = {};
    rep(i,M)rep(j,6)d_true[i][j] = 1;
    while(1){
        //time
        auto now_time = timer.get();
        if(now_time >= TL) break;

        //score and d initiation
        ll tmp_score = scan_score;
        int d_simu[M][6];
        rep(i,M)rep(j,6)d_simu[i][j] = d_true[i][j];
        //one time simulation
        int next_idx = now_idx;
        for(int i = N+30; i < M;i++){
            //change the dice
            int change_idx = XorShift() % 6;
            rep(j,6)d_simu[i][j] = d_simu[i-1][j];
            d_simu[i][change_idx] = XorShift() % 6 + 1;
            //select the dice
            int next_d = d_simu[i][XorShift() % 6];
            //next masu
            next_idx = next_idx + next_d;
            if(next_idx == N)next_idx = 0;
            else if(next_idx > N){
                next_idx = N - (next_idx - N);
            }
            tmp_score += V[next_idx];
        }
        //結果が更新されたら
        if(chmax(best_score, tmp_score)|| XorShift() % 100 < 5){
            cerr<<"更新されました: "<<tmp_score<<endl;
            rep(i,M)rep(j,6)d_true[i][j] = d_simu[i][j];
        }
    }
    //output
    /*
    for(int i = 0; i < M;i++){
        cerr<<i<<": "<<d_true[i][0]<<" "<<d_true[i][1]<<" "<<d_true[i][2]<<" "<<d_true[i][3]<<" "<<d_true[i][4]<<" "<<d_true[i][5]<<endl;
    }*/
    for(int i = N+30; i < M; i++){
        cout<<d_true[i][0]<<" "<<d_true[i][1]<<" "<<d_true[i][2]<<" "<<d_true[i][3]<<" "<<d_true[i][4]<<" "<<d_true[i][5]<<endl;
        int d_out, v, x;
        cin>>d_out>>v>>x;
    }
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    Timer timer;
    timer.reset();
    input();
    scanning();
    simulate(timer);

    return 0;
}