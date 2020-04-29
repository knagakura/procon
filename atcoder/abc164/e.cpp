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
    int money;
    ll time;
    int id;
};

const ll DMAX = 2550;
int N, M;
ll S;
vvec<edge> G;
vec<ll> C, D;
ll dp[55][DMAX];

void input(){
    cin >> N >> M >> S;
    G.resize(N);
    C.resize(N);
    D.resize(N);
    for (int i = 0; i < M; i++){
        int u, v, a; ll b;
        cin >> u >> v >> a >> b;
        u--; v--;
        G[u].push_back({u, v, a, b, i});
        G[v].push_back({v, u, a, b, i});
    }
    rep(i,N)cin >> C[i] >> D[i];
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    input();
    rep(i,N)rep(j,DMAX)dp[i][j] = INFLL;
    priority_queue<pair<ll, i_i>, vector<pair<ll, i_i>>, greater<pair<ll, i_i>>> q;
    q.push({0,{0, S}});
    dp[0][S] = 0;
    while(!q.empty()){
        int from = q.top().second.first;
        int from2 = q.top().second.second;
        ll v = q.top().first;
        q.pop();
        int tmp = from2;
        while(tmp + C[from] <= DMAX){
            if(dp[from][tmp + C[from]] > v + D[from]){
                dp[from][tmp+C[from]] = v + D[from];
                q.push({v+D[from], {from, tmp+C[from]}});
            }
            tmp += C[from];
        }
        for(auto e: G[from]){
            if(from2 < e.money)continue;
            ll w = v + e.time;
            if(dp[e.to][e.money - from2] > w){
                dp[e.to][e.money - from2] = w;
                q.push({w, {e.to, e.money-from2}});
            }
        }
    }
    for(int i = 1; i < N; i++){
        ll res = INFLL;
        for(int j = 0; j < DMAX; j++){
            chmin(res, dp[i][j]);
        }
        cout << res << endl;
    }
}