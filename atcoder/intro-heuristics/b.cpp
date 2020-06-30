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

constexpr double TL = 1.99;
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

double Prob(void){
	double ret = (double)XorShift() / UINT_MAX;
	return ret;
}

class Status{
public:
};
/*------------------------------------*/
int D = 365;
int c[30];
int s[400][30];
int t[400];
ll last[30];
void input(){
    cin >> D;
    rep(i,26)cin >> c[i];
    rep(d,D)rep(i,26)cin >> s[d][i];
    rep(d,D){
        cin >> t[d];
        t[d]--;
    }
}
ll calc(){

    ll score = 0;
    // 増える
    for(int d = 0; d < D; d++){
    }
    // 減る
    rep(i,26){
        last[i] = 0;
    }
    for(ll d = 0; d < D; d++){
        score += s[d][t[d]];
        for(int i = 0; i < 26; i++){
            if(t[d] == i)last[i] = d+1;
            score -= c[i] * ((d+1) - last[i]);
        }
        cout << score << endl;
    }
    return score;
}

void simulate(){
    /*
    Timer timer;
    timer.reset();
    while(1){
        auto now_time = timer.get();
        if(now_time >= TL) break;
        auto rest_time = TL - now_time;
    }*/
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    input();
    //simulate();
    calc();
}
