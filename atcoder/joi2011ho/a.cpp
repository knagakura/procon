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

const int INF = (ll)1e9;
const ll INFLL = (ll)1e18+1;
const ll MOD = 1000000007;
// const ll MOD = 998244353;
const long double PI = acos(-1.0);

/*
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const string dir = "DRUL";
*/

template<typename T>
class TwoDimCumsum {
public:
    int H,W;
    vector<vector<T>> d;
    TwoDimCumsum(T _H, T _W):H(_H),W(_W),d(_H+1,vector<T>(_W+1,0)){}
    // 1-indexed
    void add(int x, int y, int a){
        d[x][y] += a;
    }
    void build(){
        for(int i = 1; i <= H; ++i){
            for(int j = 1; j <= W; ++j){
                d[i][j] += d[i-1][j];
                d[i][j] += d[i][j-1];
                d[i][j] -= d[i-1][j-1];
            }
        }
    }
    //[sx, gx] & [sy, gy]
    //1-indexed
    T query(int sx, int sy, int gx, int gy){
        return d[gx][gy] - d[sx-1][gy] - d[gx][sy-1] + d[sx-1][sy-1];
    }
    //confirm the 2d vector
    void debug(){
        for(int i = 0;i <= H;++i){
            for(int j = 0; j <= W; ++j){
                cerr<<d[i][j]<<((j == W) ? "\n":" ");
            }
        }
    }
};

/*
使い方
https://atcoder.jp/contests/abc106/submissions/9873594
1. インスタンス生成 縦横決める
TwoDimCumsum<int> Cumsum(H,W);
2. 座標に埋める
Cumsum.add(x, y, 1)
3. 二次元累積和計算
Cumsum.build()
4. 区間のクエリを受ける
Cumsumq.uery(p, q)
*/

int main() {
    int H, W;
    cin >> H >> W;
    int K;
    cin >> K;
    vector<string> S(H);
    cin >> S;
    TwoDimCumsum<ll> CJ(H, W), CO(H, W), CI(H, W);
    rep(i,H)rep(j,W){
        if(S[i][j] == 'J')CJ.add(i+1, j+1, 1);
        if(S[i][j] == 'O')CO.add(i+1, j+1, 1);
        if(S[i][j] == 'I')CI.add(i+1, j+1, 1);
    }
    CJ.build();
    CO.build();
    CI.build();
    rep(i,K){
        int sx, sy, gx, gy;
        cin >> sx >> sy >> gx >> gy;
        cout << CJ.query(sx, sy, gx, gy) << " ";
        cout << CO.query(sx, sy, gx, gy) << " ";
        cout << CI.query(sx, sy, gx, gy) << endl;
    }
}
