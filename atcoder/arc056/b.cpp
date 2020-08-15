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
const ll MOD = 1000000007;
// const ll MOD = 998244353;
const double PI = acos(-1.0);
/*
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const string dir = "DRUL";
*/

vvec<int> G;
vector<int> ok;
vector<int> minn;

void bfs(int start){
    queue<int> q;
    q.push(start);
    while(not q.empty()){
        int v = q.front();
        q.pop();
        if(ok[v])continue;
        ok[v] = true;
        for(auto nv: G[v]){
            if(ok[nv])continue;
            if(v > nv)q.push(nv);
        }
    }
}

void bfs2(int start){
    queue<pair<int, int>> q;
    // priority_queue<pair<int, int>> q;
    q.push({start, start});
    minn[start] = start;
    while(not q.empty()){
        auto p = q.front();
        int m = p.first;
        int v = p.second;
        q.pop();
        if(minn[v] < m)continue;
        for(auto nv: G[v]){
            if(nv < m){
                chmin(minn[nv], nv);
                q.push({minn[nv], nv});
            }
        }
    }
}


void dijkstra(int start){
    
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int N, M, s;
    cin >> N >> M >> s;
    s--;
    G.resize(N);
    ok.assign(N,false);
    minn.assign(N,INF);
    rep(i,M){
        int u, v;
        cin >> u >> v;
        u--; v--;
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    // bfs2(s);
    // print(minn);
    // rep(i,N){
    //     if(minn[i] != INF){
    //         cout << i + 1 << endl;
    //     }
    // }

    // bfs(s);
    // rep(i,N){
    //     if(ok[i])cout << i + 1 << endl;
    // }


}

/*

単調減少に進めるならOKということなので、
今までの最小値を持って
それより小さいなら進むってことにしたらいいのかな

最小値の更新も行う感じで

*/
