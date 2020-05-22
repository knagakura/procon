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
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const string dir = "DRUL";
int H, W, T;
vector<string> S;
int si,sj;
int gi,gj;
int f(int i, int j){
    return i * W + j;
}
bool IsIn(int x,int y){
    return 0<=x&&x<H&&0<=y&&y<W;
}
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
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    cin >> H >> W;
    S.resize(H);
    rep(i,H)cin >> S[i];
    rep(i,H)rep(j,W){
        if(S[i][j] == 's'){
            si = i;
            sj = j;
        }
        if(S[i][j]  == 'g'){
            gi = i;
            gj = j;
        }
    }
    Dijkstra<ll> G((H+1)*(W+1),INFLL);
    /*make edges*/
    rep(i,H)rep(j,W){
        rep(k,4){
            int ni = i + dx[k];
            int nj = j + dy[k];
            if(not IsIn(ni,nj))continue;
            if(S[ni][nj] == '.')G.make_edge(f(i,j), f(ni,nj),0);
            if(S[ni][nj] == '#')G.make_edge(f(i,j), f(ni,nj),1);
            if(S[ni][nj] == 's')G.make_edge(f(i,j), f(ni,nj),0);
            if(S[ni][nj] == 'g')G.make_edge(f(i,j), f(ni,nj),0);
        }
    }
    G.solve(f(si,sj));
    cout << ((G.cost[f(gi,gj)] <= 2)?"YES":"NO") << endl;
}
