#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define dump(x) cerr<<#x<<": "<<x<<endl;
#define bit(k) (1LL<<(k))
typedef long long ll;
typedef pair<int, int> i_i;
typedef pair<ll, ll> l_l;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;
template< typename T1, typename T2 >
ostream &operator<<(ostream &os, const pair< T1, T2 >& p) {
  os << "{" <<p.first << ", " << p.second << "}";
  return os;
}
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
const int M = 200000;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N, Q;
    cin >> N >> Q;
    vector<priority_queue<
    pair<ll, int>
    >> pq(M);
    //幼児iがどこにいるか
    vector<l_l> youji(N);
    rep(i,N){
        int a, b;
        cin >> a >> b;
        b--;
        pq[b].push({a,i});
        youji.push_back({a,b});
    }
    ll ans = INFLL;
    rep(i,M){
        if(!pq[i].empty()){
            chmin(ans, (ll)pq[i].top().first);
        }
    }
    rep(i,Q){
        int c, d;
        cin >> c >> d;
        c--;d--;
        //幼児cの居場所が変わる前
        int pre = youji[c].second;
        while(not pq[pre].empty()){
            int top_idx = pq[pre].top().second;
            if(top_idx == c){
                pq[pre].pop();
                chmin(ans, pq[pre].top().first);
            }
            break;
        }
        if(pq[d].empty()){
            pq[d].push({youji[c].first, c});
        }
        else{
            auto to_top = pq[d].top();
            pq[d].push({youji[c].first, c});
            if(pq[d].top().second == c){
                if(ans == to_top.first){
                    ans = pq[d].top().first;
                }
            }
        }
        youji[c].second = d;
        cout << ans << endl;
    }
}