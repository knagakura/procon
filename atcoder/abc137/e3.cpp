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
struct edge{
    ll from; ll to; ll cost;
};
//vec<edge> edges;
vvec<int> to,ot;
int ok[2505];
int ko[2505];
bool OK[2505];
ll d[2505];
void dfs(int v, int p){
    if(ok[v] > 0)return;
    ok[v]++;
    for(auto nv: to[v]){
        if(nv == p)continue;
        dfs(nv, v);
    }
}
void sfd(int v, int p){
    if(ko[v] > 0)return;
    ko[v]++;
    for(auto nv: ot[v]){
        if(nv == p)continue;
        sfd(nv, v);
    }
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    ll N,M,P;
    cin >> N >> M >> P;
    vector<tuple<int, int, int>> edges;
    to.resize(N);ot.resize(N);
    rep(i, M){
        ll a, b, c;
        cin >> a >> b >> c;
        a--;b--;
        c -= P;
        c *= -1;
        //edges.push_back({a,b,c});
        edges.emplace_back(a,b,c);
        to[a].push_back(b);
        ot[b].push_back(a);
    }
    rep(i,N)ok[i] = ko[i] = 0;
    dfs(0,-1);
    sfd(N-1,-1);
    rep(i,N){
        if(ok[i] > 0 && ko[i] > 0)OK[i] = true;
    }
    //bellman ford
    rep(i,N){
        d[i] = INF;
    }
    d[0] = 0;
    //O(NM)
    int step = 0;
    bool updated = true;
    while(updated){
        //all edges
        updated = false;
        rep(i,M){
            int a,b,c;
            tie(a,b,c) = edges[i];
            if(!OK[a])continue;
            if(!OK[b])continue;
            int newD = d[a] + c;
            if(newD < d[b]){
                updated = true;
                d[b] = newD;
            }
            /*
            edge e = edges[i];
            if(!OK[e.from])continue;
            if(!OK[e.to])continue;
            if(d[e.to] > d[e.from] + e.cost){
                d[e.to] = d[e.from] + e.cost;
                updated = true;
            }*/
        }
        step++;
        if(step > N){
            cout << -1 << endl;
            return 0;
        }
    }
    ll ans = -d[N-1];
    ans = max(ans, 0LL);
    cout << ans << endl;
}