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
struct edge{
    int from;
    int to;
    int w;
    edge(int f,int t, int we){
        from = f;
        to = t;
        w = we;
    }
};
ll dist[333][333];
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N, M;
    cin >> N >> M;
    vector<edge> ve;
    rep(i,N)rep(j,N){
        if(i == j)dist[i][j] = 0;
        else dist[i][j] = INFLL;
    }
    rep(i,M){
        int u, v, w;
        cin >> u >> v >> w;
        u--;v--;
        if(u == 0)ve.emplace_back(u,v,w);
        else{
            dist[u][v] = dist[v][u] = w;
        }
    }
    rep(k,N)rep(i,N)rep(j,N){
            dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
    }
    int sz = ve.size();
    ll ans = INFLL;
    rep(i,sz)rep(j,sz){
        if(i >= j)continue;
        ll tmp = ve[i].w + dist[ve[i].to][ve[j].to] + ve[j].w;
        chmin(ans,tmp);
    }
    cout << ((ans == INFLL) ? -1 : ans) << endl;
}