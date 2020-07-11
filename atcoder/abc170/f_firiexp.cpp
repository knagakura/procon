#include <iostream>
#include <algorithm>
#include <iomanip>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <numeric>
#include <bitset>
#include <cmath>

static const int MOD = 1000000007;
using ll = long long;
using u32 = unsigned;
using u64 = unsigned long long;
using namespace std;

template<class T> constexpr T INF = ::numeric_limits<T>::max()/32*15+208;

template <class T, class U>
vector<T> make_v(U size, const T& init){ return vector<T>(static_cast<size_t>(size), init); }

template<class... Ts, class U>
auto make_v(U size, Ts... rest) { return vector<decltype(make_v(rest...))>(static_cast<size_t>(size), make_v(rest...)); }

template<class T> void chmin(T &a, const T &b){ a = (a < b ? a : b); }
template<class T> void chmax(T &a, const T &b){ a = (a > b ? a : b); }

template <typename T>
using GPQ = priority_queue<T, vector<T>, greater<T>>;

template <typename T>
struct edge {
    int from, to; T cost;
    edge(int to, T cost) : from(-1), to(to), cost(cost) {}
    edge(int from, int to, T cost) : from(from), to(to), cost(cost) {}
};

template <typename T>
vector<T> dijkstra(int s,vector<vector<edge<T>>> &G){
    auto n = G.size();
    vector<T> d(n, INF<T>);
    priority_queue<pair<T, int>,vector<pair<T, int>>,greater<>> Q;
    d[s] = 0;
    Q.emplace(0, s);
    while(!Q.empty()){
        T cost; int i;
        tie(cost, i) = Q.top(); Q.pop();
        if(d[i] < cost) continue;
        for (auto &&e : G[i]) {
            auto cost2 = cost + e.cost;
            if(d[e.to] <= cost2) continue;
            d[e.to] = cost2;
            Q.emplace(d[e.to], e.to);
        }
    }
    return d;
}

int main() {
    int n, m, k;
    cin >> n >> m >> k;
    int sy, sx, gy, gx;
    cin >> sy >> sx >> gy >> gx;
    auto grid = make_v(n+2, m+2, 0);
    for (int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        for (int j = 0; j < m; ++j) {
            grid[i+1][j+1] = (s[j] == '.');
        }
    }

    array<int, 4> dy{-1, 1, 0, 0}, dx{0, 0, -1, 1};
    auto dp = make_v(4, n+2, m+2, make_pair(INF<int>, INF<int>));
    using P = array<int, 5>;
    GPQ<P> Q;
    for (int i = 0; i < 4; ++i) {
        Q.emplace(P{0, 0, i, sy, sx});
        dp[i][sy][sx] = {0, 0};
    }
    while(!Q.empty()){
        auto to = Q.top(); Q.pop();
        int dir = to[2], y = to[3], x = to[4];
        if(dp[dir][y][x] < make_pair(to[0], to[1])) continue;
        for (int p = 0; p < 4; ++p) {
            if(grid[y+dy[p]][x+dx[p]] == 0) continue;
            auto q = dp[dir][y][x];
            if(dir == p){
                q.second++;
                if(q.second == k) q.second = 0, q.first++;
            }else {
                q.first += (q.second != 0), q.second = 1;
                if(q.second == k) q.second = 0, q.first++;
            }
            if(dp[p][y+dy[p]][x+dx[p]] <= q) continue;
            dp[p][y+dy[p]][x+dx[p]] = q;
            Q.emplace(P{q.first, q.second, p, y+dy[p], x+dx[p]});
        }
    }
    auto x = make_pair(INF<int>, INF<int>);
    for (int i = 0; i < 4; ++i) {
        x = min(x, dp[i][gy][gx]);
    }
    if(x.first > n*m){
        puts("-1");
    }else {
        printf("%d\n", x.first+(x.second != 0));
    }
    return 0;
}
