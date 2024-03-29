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


int main() {
    int H, W;
    cin >> H >> W;
    vector<string> S(H), T;
    cin >> S;
    T = S;
    auto IsIn = [&](int x, int y){
        return 0 <= x && x < H && 0 <= y && y < W;
    };
    auto bfs = [&](int si, int sj){
        vvec<int> dist(H,vector<int>(W, -1));
        vvec<int> visited(H,vector<int>(W, 0));
        // 準備
        rep(i,H)visited[i][sj] = 1;
        rep(j,W)visited[si][j] = 1;
        rep(x, H)rep(y,W)rep(j,2){
            int nx = x + dx[j+2];
            int ny = y + dy[j+2];
            if(T[nx][ny] == '#')visited[x][y]++;
        }
        dist[si][sj] = 0;
        visited[si][sj] = 2;
        queue<pair<int,int>> q;
        q.push({si, sj});
        while(not q.empty()){
            auto [x, y] = q.front();
            q.pop();
            // if(visited[x][y] < 2)continue;
            rep(j,2){
                int nx = x + dx[j];
                int ny = y + dy[j];
                if(not IsIn(nx, ny))continue;
                if(T[nx][ny] == '#')continue;
                visited[nx][ny]++;
                chmax(dist[nx][ny], dist[x][y]+1);
                if(visited[nx][ny] == 2)q.push({nx, ny});
            }
        }
        int maxx = 0, maxy = 0;
        int maxxx = 0;
        rep(i,H)rep(j,W){
            if(chmax(maxxx, dist[i][j])){
                maxx = i;
                maxy = j;
            }
        }
        T[si][sj] = '.';
        T[maxx][maxy] = '#';
        rep(i,H){
            dump(dist[i]);
        }        
        rep(i,H){
            dump(visited[i]);
        }
        rep(i,H){
            dump(T[i]);
        }
        return maxxx;
    };
    ll ans = 0;
    for(int i = H-1; i >= 0; i--){
        for(int j = W-1; j >= 0; j--){
            if(S[i][j] == 'o'){
                ll add = bfs(i,j);
                dump(i,j, add);
                ans += add;
            }
        }
    }
    cout << ans << endl;
}
