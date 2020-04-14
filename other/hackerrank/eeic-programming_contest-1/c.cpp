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
/*
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const string dir = "DRUL";
*/

template<class T> class Dijkstra {
public:
    int N;
    T inf;
    vvec<T> cost;
    //vector<vector<pair<T, int>>> edge[2];
    vec<vvec<pair<T, int>>> edge;
    Dijkstra(const int N, T inf) : N(N), inf(inf) {
        edge.resize(2);
        cost.resize(2);
        rep(j,2){
            edge[j].resize(N);
            cost[j].resize(N);
        }
    }
    void make_edge(int from, int to, T w) {
        edge[0][from].push_back({ w,to });
        edge[1][to].push_back({ w, from });
    }
 
    void solve(int start) {
        rep(j,2)for(int i = 0; i < N; ++i) cost[j][i] = inf;
 
        priority_queue<pair<T, pair<int, int>>, vector<pair<T, pair<int, int>>>, greater<pair<T, pair<int, int>>>> pq;
        cost[0][start] = 0;
        pq.push({ 0,{0,start}});
 
        while (!pq.empty()) {
            T v = pq.top().first;
            int s = pq.top().second.first;
            int from = pq.top().second.second;
            int ns = (s + 1) % 2;
            pq.pop();
            for (auto u : edge[s][from]) {
                T w = v + u.first;
                int to = u.second;
                if (w < cost[ns][to]) {
                    cost[ns][to] = w;
                    pq.push({ w,{ns,to} });
                }
            }
        }
        return;
    }
    void debug(){
        rep(i,N){
            cerr <<"from: "<<i<<" ";printpair(edge[0][i]);
        }
        rep(i,N){
            cerr <<"from: "<<i<<" ";printpair(edge[1][i]);
        }
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
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, M;
    cin >> N >> M;
    Dijkstra<ll> d(N, INFLL);
    rep(i,M){
        ll a, b, c;
        cin >> a >> b >> c;
        a--;b--;
        d.make_edge(a,b,c);
    }
    d.solve(0);

    ll ans = min(d.cost[0][N-1],d.cost[1][N-1]);
    if(ans == INFLL)ans = -1;

    cout << ans << endl;
}