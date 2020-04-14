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

int H,W;
pair<int, int> finv(int X){
    return make_pair(X / W, X % W);
}
template<class T> class Dijkstra {
public:
    int N;
    T inf;
    vector<T> cost;
    vector<int> prev;
    vector<vector<pair<T, int>>> edge;
 
    Dijkstra(const int _N, T _inf) : N(_N), inf(_inf),cost(_N), edge(_N), prev(_N,-1) {
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
                    prev[to] = from;
                    pq.push({ w,to });
                }
            }
        }
        return;
    }
    vector<int> get_path(int t){ //頂点tへの最短路
        vector<int> path;
        for(; t != -1;t=prev[t]){
            path.push_back(t);
        }
        reverse(path.begin(), path.end());
        return path;
    }
    void debug(){
        rep(i,N){
            cerr << finv(i).first << "  " << finv(i).second <<": ";printpair(edge[i]);
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

vector<string> A;
bool IsIn(int x,int y){
    return 0<=x&&x<H&&0<=y&&y<W;
}
int f(int i, int j){
    return i * W + j;
}
template<typename T>
vector<pair<T,long long>> RunLengthEncoder(vector<T> &v){
    vector<pair<T,long long>> RLE;
    long long cnt = 1;
    for(int i = 0; i < (int)v.size(); ++i){
        if(i == (int)v.size()-1){
            RLE.push_back(make_pair(v[i], cnt));
            continue;
        }
        if(v[i] == v[i+1])cnt++;
        else{
            RLE.push_back(make_pair(v[i],cnt));
            cnt = 1;
        }
    }
    return RLE;
}

vector<pair<char,long long>> RunLengthEncoder_ForString(string v){
    vector<pair<char,long long>> RLE;
    long long cnt = 1;
    for(int i = 0; i < (int)v.size(); ++i){
        if(i == (int)v.size()-1){
            RLE.push_back(make_pair(v[i], cnt));
            continue;
        }
        if(v[i] == v[i+1])cnt++;
        else{
            RLE.push_back(make_pair(v[i],cnt));
            cnt = 1;
        }
    }
    return RLE;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    cin >> H >> W;
    A.resize(H);
    rep(i,H){
        cin >> A[i];
    }
    Dijkstra<ll> d(H*W, INFLL);
    rep(i,H)rep(j,W){
        //cerr << i << " " << j <<endl;
        rep(k,2){
            int e = f(i, j);
            int nx = i + dx[k];
            int ny = j + dy[k];
            int ne = f(nx, ny);
            int cost = 0;
            if(!IsIn(nx, ny))continue;
            if(A[nx][ny] == '#')cost = 1;
            d.make_edge(e, ne, cost);
            //cerr << nx << " " << ny <<  endl;
        }
        //cerr << endl;
    }
    d.solve(f(0, 0));
    auto path = d.get_path(f(H-1, W-1));
    vector<pair<int, int>> paths;
    for(auto x: path){
        paths.push_back(finv(x));
    }
    vector<char> path_col;
    for(auto p: paths){
        path_col.push_back(A[p.first][p.second]);
    }
    auto rle = RunLengthEncoder(path_col);
    
    d.debug();
    print(d.prev)
    print(path);
    printpair(paths);
    print(path_col);
    printpair(rle);
    
    ll ans = 0;
    for(auto p: rle){
        if(p.first == '#')ans++;
    }
    cout << ans <<  endl;
}