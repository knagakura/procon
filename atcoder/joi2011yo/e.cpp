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

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int H, W, N;
bool IsIn(int x,int y){
    return 0<=x&&x<H&&0<=y&&y<W;
}
int main() {
    cin >> H >> W >> N;
    vector<string> S(H);
    rep(i,H)cin >> S[i];
    rep(i,H)rep(j,W)if(S[i][j] == 'S')S[i][j] = '0';
    vector<i_i> vp(N+1);
    rep(i,H)rep(j,W){
        if(0 <= S[i][j] - '0' && S[i][j] - '0' <= 9){
            vp[S[i][j] - '0'].first = i;
            vp[S[i][j] - '0'].second = j;
        }
    }
    auto bfs = [&](int sx, int sy, int gx, int gy) -> int{
        vvec<int> d(H, vec<int>(W, INF));
        queue<i_i> q;
        q.push({sx, sy});
        d[sx][sy] = 0;
        while(not q.empty()){
            auto [x, y] = q.front();
            q.pop();
            rep(i,4){
                int nx = x + dx[i];
                int ny = y + dy[i];
                if(not IsIn(nx, ny))continue;
                if(S[nx][ny] == 'X')continue;
                if(d[nx][ny] < INF)continue;
                d[nx][ny] = d[x][y] + 1;
                q.push({nx, ny});
            }
        }
        return d[gx][gy];
    };
    ll ans = 0;
    rep(i,N){
        auto [sx, sy] = vp[i];
        auto [gx, gy] = vp[i+1];
        ans += bfs(sx, sy, gx, gy);
    }
    cout << ans << endl;
}
