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
template <typename T> ostream &operator<<(ostream &os, multiset<T> &st) { os << "("; for(auto _: st) { os << _ << ", "; } os << ")";return os;}
template <typename T, typename U> ostream &operator<<(ostream &os, const pair< T, U >& p){os << "{" <<p.first << ", " << p.second << "}";return os; }
template <typename T, typename U> ostream &operator<<(ostream &os, const map<T, U> &mp){ os << "["; for(auto _: mp){ os << _ << ", "; } os << "]" << endl; return os; }

#define DUMPOUT cerr
void dump_func(){ DUMPOUT << endl; }
template <class Head, class... Tail> void dump_func(Head &&head, Tail &&... tail) { DUMPOUT << head; if (sizeof...(Tail) > 0) { DUMPOUT << ", "; } dump_func(std::move(tail)...); }

#ifdef DEBUG
#define dbg(...) { dump_func(__VA_ARGS__) }
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

template<class T> class Dijkstra {
public:
    int N;
    T inf;
    vector<T> cost;
    vector<vector<pair<T, int>>> edge;
 
    Dijkstra(const int N, T inf) : N(N), inf(inf),cost(N), edge(N) {
    }
 
    void make_edge(int from, int to, T w) {
        edge[from].push_back({ w,to });
    }
 
    void solve(int start) {
        for(int i = 0; i < N; ++i) cost[i] = inf;
 
        priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> pq;
        cost[start] = 0;
        pq.push({ 0,start });
 
        while (!pq.empty()) {
            T v = pq.top().first;
            int from = pq.top().second;
            pq.pop();
            for (auto u : edge[from]) {
                T w = v + u.first;
                int to = u.second;
                if (w < cost[to]) {
                    cost[to] = w;
                    pq.push({ w,to });
                }
            }
        }
        return;
    }
};

/*
使い方
1. まずインスタンス生成
重みの型、頂点の数、距離の無限大のINFLL
Dijkstra<ll> d(N, INFLL);

2. 辺を貼る
iからjに重みwの辺を貼る場合
d.make_edge(i,j,w);

3. 頂点sから解く
d.solve(s);

4. sからgの距離
d.cost[g]

GigaCode2019 E - 車の乗り継ぎ
https://atcoder.jp/contests/gigacode-2019/submissions/8651446

*/
int main() {

    int H, W;
    cin >> H >> W;
    int sx = 0, sy = 0;
    int gx = 0, gy = 0;
    vector<string> a(H);
    cin >> a;
    vector<vector<pair<int, int>>> v(26);
    rep(i,H)rep(j,W){
        if(a[i][j] == '#')continue;
        else if(a[i][j] == '.')continue;
        else if(a[i][j] == 'S'){
            sx = i, sy = j;
        }
        else if(a[i][j] == 'G'){
            gx = i, gy = j;
        }
        else{
            v[a[i][j]-'a'].emplace_back(i, j);
        }
    }
    auto IsIn = [&](int i,int j) -> bool{
        return 0 <= i && i < H && 0 <= j && j < W;
    };
    vector<int> d_i_from_g(26, INF);
    vvec<int> dc2c(26,vector<int>(26, INF));
    rep(i,26)dc2c[i][i] = 0;
    // それぞれの頂点からゴールまでの最短距離を求める
    rep(i,26){
        queue<pair<int, int>> q;
        vvec<int> dist(H, vector<int>(W, INF));
        for(auto [x, y]: v[i]){
            dist[x][y] = 0;
            q.push({x, y});
        }
        while(not q.empty()){
            auto[x, y] = q.front();
            q.pop();
            rep(k,4){
                int nx = x + dx[k];
                int ny = y + dy[k];
                if(not IsIn(nx, ny))continue;
                if(a[nx][ny] == '#')continue;
                if(dist[nx][ny] < INF)continue;
                dist[nx][ny] = dist[x][y] + 1;
                if(a[nx][ny] - 'a' >= 0 && a[nx][ny] - 'a' < 26){
                    chmin(dc2c[i][a[nx][ny]-'a'], dist[nx][ny]);
                }
                q.push({nx, ny});
            }
        }
        d_i_from_g[i] = dist[gx][gy];
    }
    vector<int> d_s_from_i(26, INF);
    queue<pair<int,int>> q;
    vvec<int> dist(H, vector<int>(W, -1));
    dist[sx][sy] = 0;
    int ans = INF;
    q.push({sx, sy});
    while(not q.empty()){
        auto[x, y] = q.front();
        q.pop();
        rep(k,4){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(not IsIn(nx, ny))continue;
            if(a[nx][ny] == '#')continue;
            if(dist[nx][ny] >= 0)continue;
            dist[nx][ny] = dist[x][y] + 1;
            // g, a, .
            if(a[nx][ny] == 'G'){
                chmin(ans, dist[nx][ny]);
            }
            else if(a[nx][ny] - 'a' < 26){
                chmin(d_s_from_i[a[nx][ny]-'a'], dist[nx][ny]);
            }
            q.push({nx, ny});
        }
    }
    // dump(sx, sy);
    // dump(gx, gy);
    // dump(d_s_from_i);
    // dump(d_i_from_g);
    // rep(i,H){
    //     dump(dist[i]);
    // }
    // DUMPOUT << endl;
    // rep(i,26){
    //     dump(dc2c[i]);
    // }
    rep(i,26)rep(j,26){
        if(dc2c[i][j] == INF)continue;
        if(d_s_from_i[i] ==INF)continue;
        if(d_i_from_g[i] == INF)continue;
        if(chmin(ans, d_s_from_i[i] + dc2c[i][j] + d_i_from_g[j] + 1 + (i != j))){
        }
    }
    int szz = 60;
    int si = 26*2+1, gi = si+1;
    Dijkstra<ll> G(szz, INF);
    rep(i,26){
        G.make_edge(si, i, d_s_from_i[i]);
    }
    rep(i,26)rep(j,26){
        int tj = j + 26;
        G.make_edge(i, tj, dc2c[i][j]+(i!=j));
        G.make_edge(tj, i, dc2c[i][j]+(i!=j));
    }
    rep(i,26){
        int ti = i+26;
        G.make_edge(ti, gi, d_i_from_g[i]);
        G.make_edge(i, gi, d_i_from_g[i]);
    }
    G.solve(si);
    ll anss = G.cost[gi]+1;
    dump(anss);
    if(anss >= INF){
        cout << -1 << endl;
    }
    else{
        cout << anss << endl;
    }
}
