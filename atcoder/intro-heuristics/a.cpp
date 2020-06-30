#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define dump(x) cerr<<#x<<": "<<x<<endl;
#define bit(k) (1LL<<(k))
typedef long long ll;
typedef pair<int, int> i_i;
typedef pair<ll, ll> l_l;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;
template< typename T1, typename T2 >
ostream &operator<<(ostream &os, const pair< T1, T2 >& p) {
  os << "{" <<p.first << ", " << p.second << "}";
  return os;
}
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

vvec<ll> last(400,vec<ll>(30));
void input(){
    cin >> D;
    rep(i,26)cin >> c[i];
    rep(d,D)rep(i,26)cin >> s[d][i];
}

//割り当てを与えたら計算する
vector<ll> calc(vector<int> &v){
    vector<ll> scores(D+1,0);
    rep(d,D+1)rep(i,26)last[d][i] = 0;
    for(ll d = 0; d < D; d++){
        scores[d+1] = scores[d];
        scores[d+1] += s[d][v[d]];
        for(int i = 0; i < 26; i++){
            last[d+1][i] = last[d][i];
            if(v[d] == i)last[d+1][i] = d+1;
            scores[d+1] -= c[i] * ((d+1) - last[d+1][i]);
        }
    }
    return scores;
}
//途中まで計算されているのでその後だけ計算する
vector<ll> calc(vector<int> &v, int ch_idx, int pre_fix_score, vvec<ll>&last_vec){
    vector<ll> scores(D+1,0);
    scores[++ch_idx] = pre_fix_score;
    for(ll d = ch_idx; d < D; d++){
        scores[d+1] = scores[d];
        scores[d+1] += s[d][v[d]];
        rep(i,26){
            last_vec[d+1][i] = last_vec[d][i];
            if(v[d] == i)last_vec[d+1][i] = d+1;
            scores[d+1] -= c[i] * ((d+1) - last_vec[d+1][i]);
        }
    }
    return scores;
}
void simulate(){
    Timer timer;
    timer.reset();
    vector<int> pre(D);
    for(int d = 0; d < D; d++){
        pre[d] = XorShift() % 26;
    }
    auto pre_scores = calc(pre);
    dump(pre_scores.back());
    while(1){
        auto now_time = timer.get();
        if(now_time >= TL) break;
        auto rest_time = TL - now_time;
        // random change
        int chidx = XorShift()%D;
        int chtype = XorShift()%26;
        vector<int> nxt = pre;
        nxt[chidx] = chtype;
        auto nxt_last = last;
        auto nxt_scores = calc(nxt, chidx, pre_scores[chidx], nxt_last);
        if(pre_scores.back() < nxt_scores.back()){
            swap(pre, nxt);
            swap(pre_scores, nxt_scores);
            swap(last, nxt_last);
        }
    }
    rep(i,D){
        cout << pre[i] + 1 << endl;
    }
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    input();
    simulate();
}
