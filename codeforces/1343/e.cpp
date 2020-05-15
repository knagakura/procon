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
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b ; return true; } return false; }

const int INF = (ll)1e9;
const ll INFLL = (ll)1e18+1;
const ll MOD = (ll)1e9+7;
const double PI = acos(-1.0);
/*
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const string dir = "DRUL";
*/

int N, M, a, b, c;
vector<ll> p;
vvec<int> G;

vector<ll> dist(int s){
    queue<int> q;
    vec<bool> vis(N, false);
    vec<ll> d(N, INFLL);
    q.push(s);
    d[s] = 0;
    vis[s] = true;
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(auto& nv: G[v]){
            if(vis[nv])continue;
            d[nv] = d[v] + 1;
            q.push(nv);
            vis[nv] = true;
        }
    }
    return d;
}

void solve(){

    cin >> N >> M >> a >> b >> c;
    a--, b--, c--;

    p.resize(M);
    rep(i,M)cin >> p[i];
    sort(all(p));

    G.resize(N);

    rep(i,M){
        int x, y;
        cin >> x >> y;
        x--, y--;
        G[x].push_back(y);
        G[y].push_back(x);
    }
    auto da = dist(a);
    auto db = dist(b);
    auto dc = dist(c);
    // xを中継地点として、a -> x -> b -> x -> c
    vector<ll> cum(M+1, 0);
    rep(i,M)cum[i+1] = cum[i] + p[i];
    ll ans = INFLL;
    rep(x, N){
        int idx = da[x] + db[x] + dc[x];
        if(idx > M)continue;
        ll tmp = cum[db[x]] + cum[idx];
        chmin(ans, tmp);
    }
    cout << ans << endl;
    G.clear();
    p.clear();
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int t;
    cin >> t;
    while(t--)solve();
}