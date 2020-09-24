#include <bits/stdc++.h>
#include <atcoder/maxflow>
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

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const string dir = "DRUL";

int main() {
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    rep(i,H)cin >> S[i];
    atcoder::mf_graph<ll> G(H*W+2);
    int s = H * W;
    int t = s + 1;
    auto IsIn = [&](int i,int j) -> bool{
        return 0 <= i && i < H && 0 <= j && j < W;
    };
    auto f = [&](int i, int j) -> int{
        return i * W + j;
    };
    rep(i,H)rep(j,W){
        if(S[i][j] == '#')continue;
        if((i+j)&1)G.add_edge(f(i,j), t, 1);
        else G.add_edge(s, f(i,j), 1);
        rep(k,2){
            int ni = i + dx[k];
            int nj = j + dy[k];
            if(not IsIn(ni, nj))continue;
            if(S[ni][nj] == '#')continue;
            int from = f(i, j);
            int to = f(ni, nj);
            if((i+j)&1)swap(from, to);
            // fromが偶数
            // toが奇数
            G.add_edge(from, to, 1);
        }
    }
    ll ans = G.flow(s, t);
    for(auto e: G.edges()){
        if(e.flow > 0 && e.from < H*W && e.to < H*W){
            int sx = e.from / W;
            int sy = e.from % W;
            int gx = e.to / W;
            int gy = e.to % W;
            dump(sx, sy, gx, gy);
            if(sx == gx){
                S[sx][sy] = '<';
                S[gx][gy] = '>';
                if(sy < gy)swap(S[sx][sy], S[gx][gy]);
            }
            if(sy == gy){
                S[sx][sy] = '^';
                S[gx][gy] = 'v';
                if(sx < gx)swap(S[sx][sy], S[gx][gy]);
            }
        }
    }
    cout << ans << endl;
    rep(i,H)cout << S[i] << endl;
}