#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define dump(x) cerr<<#x<<": "<<x<<endl;
typedef long long ll;
const ll INFLL = (ll)1e18+1;

template <typename T>
class Grid{
  public:
    int H, W, sz;    /*  ↓   →　 ↑　　←　 ↘️   ↗️   ↖️   ↙️  */
    const int di[8]  = { 1,  0, -1,  0,  1, -1, -1,  1 };
    const int dj[8]  = { 0,  1,  0, -1,  1,  1, -1, -1 };
    const string dir =  "DRUL";
    const T inf;
    vector<T> cost;
    vector<string> Board;
    vector<vector<pair<T, int>>> edge;
    Grid(int _H, int _W, T _inf):H(_H), W(_W),sz(_H*_W), inf(_inf){
        Board.resize(H);
        cost.assign(sz, inf);
        edge.resize(sz);
    }
    void input(){
        for(int i = 0; i < H; i++){
            cin >> Board[i];
        }
    }
    void input2(){
        for(int i = 0; i < H; i++){
            for(int j = 0; j < W; j++){
                char c; cin >> c;
                Board[i].push_back(c);
            }
        }
    }
    // member function
    void make_edge(int from_i, int from_j) {
        make_edge_setting(from_i, from_j);
    }
    void make_edge_setting(int i, int j){
        /* change by problems */
        /* sample */
        for(int k = 0; k < 2; k++){
            //
            int ni = i + di[k];
            int nj = j + dj[k];
            if(!isin(ni, nj))continue;
            int w = 0;
            if(Board[i][j] == '.' && Board[ni][nj] == '#')w++;
            //
            make_edge(i, j, ni, nj, w);
        }
    }
    void make_edge(int i, int j, int ni, int nj, T w){
        int from = oneD_index(i, j);
        int to = oneD_index(ni, nj);
        edge[from].push_back({w, to});
    }

    void dijkstra(int s_i, int s_j) {
        cost.assign(sz, inf);
        int start = oneD_index(s_i, s_j);
        priority_queue<pair<T, int>, vector<pair<T, int>>, greater<pair<T, int>>> pq;
        cost[start] = 0;
        pq.push({0, start});
        while (!pq.empty()){
            T v = pq.top().first;
            int from = pq.top().second;
            pq.pop();
            for (auto u: edge[from]){
                T w = v + u.first;
                int to = u.second;
                if (w < cost[to]){
                    cost[to] = w;
                    pq.push({w, to});
                }
            }
        }
        return;
    }

    void debug_graph(){
        cerr << endl << " from :  {  to  ,  w}" << endl;
        for(int idx = 0; idx < sz;idx++){
            auto twoD = twoD_index(idx);
            cerr << "("<< twoD.first << ", " << twoD.second << "): ";
            cerr << "[";
            for(auto p: edge[idx]){
                auto to = twoD_index(p.second);
                int w = p.first;
                cerr << "{(" << to.first << ", " << to.second << ") , " << w << "}, ";
            }
            cerr << "]" << endl;
        }
        cerr << endl;
    }
    bool isin(int x,int y){
        return 0<=x&&x<H&&0<=y&&y<W;
    }
    int oneD_index(int i, int j){
        return i * W + j;
    }
    pair<int, int> twoD_index(int idx){
        return make_pair(idx / W, idx % W);
    }
};
int main() {
    int H, W;
    cin >> H >> W;
    Grid<ll> g(H, W, INFLL);
    g.input();
    rep(i,H)rep(j,W){
        g.make_edge(i, j);
    }
    //g.debug_graph();
    g.dijkstra(0, 0);
    //print(g.cost);
    ll ans = g.cost[g.oneD_index(H-1, W-1)];
    if(g.Board[0][0] == '#')ans++;
    cout << ans << endl;
}