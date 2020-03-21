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
vec<edge> edges;
vvec<int> to,ot;
int ok[2500];
int ko[2500];
ll d[2500];
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
    to.resize(N);ot.resize(N);
    rep(i, M){
        ll a, b, c;
        cin >> a >> b >> c;
        c -= P;
        a--;b--;
        edges.push_back({a,b,-c});
        to[a].push_back(b);
        ot[b].push_back(a);
    }
    dfs(0,-1);
    sfd(N-1,-1);
    //bellman ford
    rep(i,N){
        d[i] = INFLL;
    }
    d[0] = 0;
    //O(NM)
    int cnt = 0;
    while(1){
        cnt++;
        //all edges
        bool updated = false;
        rep(i,M){
            edge e = edges[i];
            if(ok[e.to] == 0 ||ko[e.to] ==  0)continue;
            if(ok[e.from] == 0 ||ko[e.from] ==  0)continue;
            if(chmin(d[e.to], d[e.from] + e.cost)){
                updated = true;
            }
        }
        if(!updated)break;;
        if(cnt > N && updated){
            cout << -1 << endl;
            return 0;
        }
    }
    cout << max(0LL, -d[N-1]) << endl;
}
