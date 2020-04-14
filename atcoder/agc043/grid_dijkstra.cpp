#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)

typedef long long ll;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const ll INFLL = (ll)1e18+1;

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};


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

int H,W;
vector<string> A;
bool IsIn(int x,int y){
    return 0<=x&&x<H&&0<=y&&y<W;
}
int f(int i, int j){
    return i * W + j;
}

int main() {

    cin >> H >> W;
    A.resize(H);
    rep(i,H){
        cin >> A[i];
    }
    Dijkstra<ll> d(H*W, INFLL);
    rep(i,H)rep(j,W){
        rep(k,2){
            int e = f(i, j);
            int nx = i + dx[k];
            int ny = j + dy[k];
            int ne = f(nx, ny);
            int cost = 0;
            if(!IsIn(nx, ny))continue;
            if(A[i][j] == '.' && A[nx][ny] == '#')cost = 1;
            d.make_edge(e, ne, cost);
        }
    }
    d.solve(f(0, 0));

    ll ans = d.cost[f(H-1, W-1)];
    if(A[0][0] ==  '#')ans++;
    cout << ans <<  endl;
}