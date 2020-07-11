#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
typedef long long ll;
typedef pair<ll, ll> l_l;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const ll INFLL = (ll)1e15+1;
const int dx[8] = {1, 0, -1, 0};
const int dy[8] = {0, 1, 0, -1};

l_l dist[1010][1010][10];

int main() {

    ll H, W, K;
    int sx, sy, gx, gy;
    cin >> H >> W >> K;
    cin >> sx >> sy >> gx >> gy;
    sx--, sy--, gx--, gy--;
    vector<string> S(H);
    rep(i,H)cin >> S[i];
    auto f = [&](ll a, ll b){
        return a * W + b;
    };
    auto g = [&](ll c, ll d){
        return c * 4 + d;
    };
    auto h = [&](ll x, ll y, ll z){
        return g(f(x, y), z);
    };
    rep(i,H)rep(j,W)rep(k,4)dist[i][j][k] = {INFLL,INFLL};
    // {{移動回数, K回以下の進行回数}, 座標 }
    priority_queue<pair<l_l,int>,
    vector<pair<l_l,int>>,
    greater<>> pq;

    rep(k,4)pq.push({{0,0},h(sx,sy,k)});
    rep(k,4)dist[sx][sy][k] = {0LL,0LL};

    while(!pq.empty()){
        auto tmp = pq.top();
        pq.pop();
        auto now_dist = tmp.first;
        ll d = tmp.first.first;
        ll cnt = tmp.first.second;
        ll idx = tmp.second;
        ll x = idx/4/W;
        ll y = idx/4%W;
        ll dir = idx % 4;
        //cerr << x+1 << " " << y+1 << " " << dir << " " << now_dist << " " << endl;
        if(dist[x][y][dir] < now_dist)continue;
        rep(j,4){
            int nx = x + dx[j];
            int ny = y + dy[j];
            ll nxt_d = d;
            ll nxt_cnt = cnt;
            if(nx < 0 || H <= nx || ny < 0 || W <= ny)continue;
            if(S[nx][ny] == '@')continue;
            if(j == dir){
                nxt_cnt++;
                if(nxt_cnt == K){
                    nxt_cnt = 0;
                    nxt_d++;
                }
            }
            else{
                nxt_d += nxt_cnt != 0;
                nxt_cnt = 1;
                if(nxt_cnt == K){
                    nxt_cnt = 0;
                    nxt_d++;
                }
            }
            l_l nxt_dist = make_pair(nxt_d, nxt_cnt);
            if(chmin(dist[nx][ny][j], nxt_dist)){
                pq.push({dist[nx][ny][j], h(nx, ny, j)});
            }
        }
    }

    l_l ans = {INFLL, INFLL};
    rep(j,4)chmin(ans, dist[gx][gy][j]);
    cout << ((ans.first > H * W)? -1: ans.first + (ans.second != 0)) << endl;
}

