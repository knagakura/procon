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
ll N,M;
struct edge
{
    ll from; ll to; ll cost;
};
vector<edge> edges;
vector<ll> to[1010], ot[1010];
bool ok[1010], ko[1010];
bool dok[1010];
ll d[1010];

void debug(){
    rep(i,N){
        cerr << d[i] <<" ";
    }
    cerr << endl;
}
void dfs(ll v, ll p){
    if(ok[v])return;
    ok[v] = true;
    for(auto nv: to[v]){
        if(nv == p)continue;
        dfs(nv, v);
    }
}
void rdfs(ll v, ll p){
    if(ko[v])return;
    ko[v] = true;
    for(auto nv: ot[v]){
        if(nv == p)continue;
        rdfs(nv, v);
    }
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    cin >> N >> M;
    rep(i,M){
        ll a, b, c;
        cin >> a >> b >> c;
        a--;b--;
        edges.push_back({a,b,-c});
        to[a].push_back(b);
        ot[b].push_back(a);
    }
    dfs(0,-1);
    rdfs(N-1, -1);
    rep(i,N)dok[i] = ok[i] & ko[i];
    rep(i,N)d[i] = INFLL;
    d[0] = 0;
    //bellman ford
    ll step = 0;
    while(1){
        //debug();
        bool upd = false;
        rep(i,M){
            edge e = edges[i];
            if(!dok[e.from])continue;
            if(!dok[e.to])continue;
            if(chmin(d[e.to], d[e.from] + e.cost)){
                upd = true;
            }
        }

        step++;
        if(!upd)break;
        if(step > N){
            cout << "inf" << endl;
            return 0;
        }
    }
    ll ans = -d[N-1];
    cout << ans << endl;
}