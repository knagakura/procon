#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define dump(x) cerr<<#x<<": "<<x<<endl;
#define bit(k) (1LL<<(k))
#define Yes "Yes"
#define No "No"
#define YES "YES"
#define NO "NO"
typedef long long ll;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = (ll)1e9;
const ll INFLL = (ll)1e18+1;
const ll MOD = (ll)1e9+7;
const double PI = acos(-1.0);

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const string dir = "DRUL";
template<class T> class Dijkstra {
public:
    int N;
    T inf;
    vector<T> cost;
    vector<vector<pair<T, int>>> edge;
 
    Dijkstra(const int _N, T _inf) : N(_N), inf(_inf),cost(_N), edge(_N) {
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
int H,W;
ll A[55][55];
bool IsIn(int x,int y){
    return 0<=x&&x<H&&0<=y&&y<W;
}
int f(int i, int j){
    return i * W + j;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    cin >> H >> W;
    rep(i,H)rep(j,W){
        cin >> A[i][j];
    }
    Dijkstra<ll> d1(H*W, INFLL);
    Dijkstra<ll> d2(H*W, INFLL);
    Dijkstra<ll> d3(H*W, INFLL);
    rep(i,H)rep(j,W){
        rep(k,4){
            int e = f(i, j);
            int nx = i + dx[k];
            int ny = j + dy[k];
            int ne = f(nx, ny);
            if(!IsIn(nx, ny))continue;
            d1.make_edge(e, ne, A[nx][ny]);
            d2.make_edge(e, ne, A[nx][ny]);
            d3.make_edge(e, ne, A[nx][ny]);
        }
    }
    d1.solve(f(H-1, 0));
    d2.solve(f(H-1, W-1));
    d3.solve(f(0, W-1));
    
    ll ans = INFLL;
    rep(i,H)rep(j,W){
        ll mid = f(i, j);
        ll cost = d1.cost[mid] + d2.cost[mid] + d3.cost[mid] - 2 * A[i][j];
        chmin(ans, cost);
    }
    cout << ans << endl;
}