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

constexpr double TL = 2.09;
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
ll last[30];

vector<int> f(){
    vector<int> vec(D);
    for (ll i = 0; i < D - 1; i++)
    {
        // ll day = i;
        // last[day] = i + 1;
        ll true_day = 0;
        ll tmp = -1001001001;
        for (int day = 0; day < 26; day++) // 実際に選ぶひにち。
        {
            ll sad = 0;
            ll score = s[i][day];
            for (int j = 0; j < 26; j++)
            {
                if (day == j)
                {
                    continue;
                }
                sad += c[j] * (i + 1 - last[j]);
            }
            for (int day1 = 0; day1 < 26; day1++)
            {
                ll score1 = s[i + 1][day1];
                ll sad1 = 0;
                for (int j = 0; j < 26; j++)
                {
                    if (day1 == j)
                    {
                        continue;
                    }
                    if (j == day)
                    {
                        sad1 += c[j];
                    }
                    else
                    {
                        sad1 += c[j] * (i + 2 - last[j]);
                    }
                }
                if (chmax(tmp, score + score1 - sad - sad1))
                {
                    true_day = day;
                }
            }
        }
        if (i % 30 == 0)
        {
            ll MAX = 0;
            ll true_day = 0;
            for (int x = 0; x < 26; x++)
            {
                if (chmax(MAX, (ll)s[i][x]))
                {
                    true_day = x;
                }
            }
        }
        last[true_day] = i + 1;
        vec[i] = true_day + 1;
    }

    ll true_day = 0;
    ll tmp = -1001001001;
    for (int day = 0; day < 26; day++) // 実際に選ぶひにち。
    {
        ll sad = 0;
        ll score = s[D - 1][day];
        for (int j = 0; j < 26; j++)
        {
            if (day == j)
            {
                continue;
            }
            sad += c[j] * (D - last[j]);
        }
        if (chmax(tmp, score - sad))
        {
            true_day = day;
        }
    }
    vec[D - 1] = true_day + 1;
    return vec;
}
void input(){
    cin >> D;
    rep(i,26)cin >> c[i];
    rep(d,D)rep(i,26)cin >> s[d][i];
}
//割り当てを与えたら計算する
ll calc(vector<int> &v){
    ll score = 0;
    // 増える
    // 減る
    rep(i,26)last[i] = 0;
    for(ll d = 0; d < D; d++){
        score += s[d][v[d]];
        for(int i = 0; i < 26; i++){
            if(v[d] == i)last[i] = d+1;
            score -= c[i] * ((d+1) - last[i]);
        }
        //cout << score << endl;
    }
    return score;
}
void simulate(){
    Timer timer;
    timer.reset();
    vector<int> pre = f();
    /*
    for(int d = 0; d < D; d++){
        pre[d] = d % 26;
    }*/
    ll pre_score = calc(pre);
    double C = TL * 200;
    ll best_score = pre_score;
    vector<int> best_result = pre;
    while(1){
        auto now_time = timer.get();
        if(now_time >= TL) break;
        auto rest_time = TL - now_time;
        auto next = rest_time*rest_time / C;
        // random change
        int chidx = XorShift()%D;
        int chtype = XorShift()%26;
        if(pre[chidx] == chtype)continue;
        vector<int> nxt = pre;
        nxt[chidx] = chtype;
        ll nxt_score = calc(nxt);
        if(pre_score < nxt_score || next > Prob()){
            pre = nxt;
            pre_score = nxt_score;
            if(chmax(best_score, pre_score)){
                best_result = pre;
            }
        }
    }
    rep(i,D){
        cout << best_result[i] + 1 << endl;
    }
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    input();
    simulate();
}
