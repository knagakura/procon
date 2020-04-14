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
}

void dice_out(){
    rep(j,6){
        cout<<d[j];
        if(j == 5)cout<<endl;
        else cout<<" ";
    }
}
//Vの値が全て見えているので、42マス
void simulate(Timer& timer){
    rep(i,M){
        dice_out();
        int d_out, next_v, next_idx;
        cin>>d_out>>next_v>>next_idx;
        V[next_idx] = next_v;
        if(next_idx < 250){
            rep(j,6){
                if(XorShift() % 100 < 5){
                    d[j] = XorShift() % 3 + 4;
                    break;
                }
                if(d[j] != 6){
                    d[j] = 6;
                    break;
                }
            }
        }
        if(next_idx > 500 - 42){
            rep(j,6){
                if(d[j] != 1){
                    d[j] = XorShift() % 2 + 1;
                    break;
                }
            }
        }
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
