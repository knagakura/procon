#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define bit(k) (1LL<<(k))
#define SUM(v) accumulate(all(v), 0LL)

typedef pair<int, int> i_i;
typedef pair<ll, ll> l_l;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;
struct fast_ios{ fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; }fast_ios_;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

#define TOSTRING(x) string(#x)
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (T &x : vec) is >> x; return is; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) { os  << "["; for(auto _: v) os << _ << ", "; os << "]"; return os; };
template <typename T> ostream &operator<<(ostream &os, set<T> &st) { os << "("; for(auto _: st) { os << _ << ", "; } os << ")";return os;}
template <typename T, typename U> ostream &operator<<(ostream &os, const pair< T, U >& p){os << "{" <<p.first << ", " << p.second << "}";return os; }
template <typename T, typename U> ostream &operator<<(ostream &os, const map<T, U> &mp){ os << "["; for(auto _: mp){ os << _ << ", "; } os << "]" << endl; return os; }

#define DUMPOUT cerr
void dump_func(){ DUMPOUT << endl; }
template <class Head, class... Tail> void dump_func(Head &&head, Tail &&... tail) { DUMPOUT << head; if (sizeof...(Tail) > 0) { DUMPOUT << ", "; } dump_func(std::move(tail)...); }

#ifdef DEBUG
#define dbg(...) dump_func(__VA_ARGS__)
#define dump(...) DUMPOUT << string(#__VA_ARGS__) << ": "; dump_func(__VA_ARGS__)
#else
#define dbg(...)
#define dump(...)
#endif

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

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
/*------------------------------------------------------------------------*/

int id, N, K;
int cnt[10];
int A[110][110];
int mawa[110][110];
vector<pair<int,int>> uni[5];
vector<pair<i_i, int>> ans;
const int col = 0;

priority_queue<pair<int, i_i>> pq; //{周りの同色の数, {座標}}
/*------------------------------------------------------------------------*/

void input(){
    cin >> id >> N >> K;
    rep(i,N){
        string S;
        cin >> S;
        rep(j,N){
            A[i][j] = S[j] - '1';
        }
    }
}
bool IsIn(int i,int j){
    return 0 <= i && i < N && 0 <= j && j < N;
};

// 変わったかどうかも返す
bool mawari(int x, int y){
    int pre_mawa = mawa[x][y];
    if(A[x][y] == col){
        mawa[x][y] = -1;
        return pre_mawa != mawa[x][y];
    }
    int res = 0;
    rep(k,4){
        int nx = x + dx[k];
        int ny = y + dy[k];
        if(not IsIn(nx, ny))continue;
        res += A[x][y] == A[nx][ny];
    }
    mawa[x][y] = res;
    return pre_mawa != mawa[x][y];
};

// 座標(x, y)をi色からj色に変える
// 変えたら、現在の状況の更新も行う
void apply(int x, int y, int i, int j){
    A[x][y] = j;
    rep(k,4){
        int nx = x + dx[k];
        int ny = y + dy[k];
        if(not IsIn(nx, ny))continue;
        if(A[nx][ny] == i)A[nx][ny] = j;
    }
    rep(k,4){
        int nx = x + dx[k];
        int ny = y + dy[k];
        if(not IsIn(nx, ny))continue;
        if(mawari(nx, ny)){
            pq.push({mawa[nx][ny], {nx, ny}});
        }
    }
    ans.push_back({{x, y}, j});
}

/*------------------------------------------------------------------------*/

void calc(){
    rep(i,N)rep(j,N){
        cnt[A[i][j]]++;
        if(A[i][j] > 0){
            mawari(i,j);
            if(mawa[i][j] == -1)continue;
            uni[mawa[i][j]].emplace_back(i,j);
            pq.push({mawa[i][j], {i, j}}); // 周りが大きい順に
        }
    }
    rep(i,K){
        dump(cnt[i]);
    }
    rep(i,5){
        dump(uni[i].size());
    }
}
void simulate(){
    while(not pq.empty()){
        auto [mawa_was, p] = pq.top();
        auto [x, y] = p;
        pq.pop();
        if(mawa[x][y] != mawa_was)continue; // 状況が一致しないなら、前に入れられたやつ
        if(A[x][y] == col)continue; // 色がcolなら、しない
        apply(x, y, A[x][y], col);
    }
}
void output(){
    int M = ans.size();
    chmin(M, N*N);
    cout << M << endl;
    rep(i,M){
        auto [p, iro] = ans[i];
        auto [x, y] = p;
        cout << x+1 << " " << y+1 << " " << iro+1 << endl;
    }
    dump(M);
    // rep(i,N){
    //     rep(j,N){
    //         cerr << A[i][j];
    //     }
    //     cerr << endl;
    // }
}
int main() {
    input(); // 入力
    calc(); // 盤面の状態を計算する
    simulate(); // 実際に答えを計算してく
    output(); // 出力
}
