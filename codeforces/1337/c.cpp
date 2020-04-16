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
int N, K;
vvec<int> G;
vec<ll> sz,d;
vec<ll> add;
vector<bool> ok;

int dfs(int cur = 0, int pre = -1, int cnt = 0){
    d[cur] = cnt;
    int res = 1;
    for(auto nxt: G[cur]){
        if(nxt == pre)continue;
        res += dfs(nxt, cur, cnt+1);
    }
    return sz[cur] = res;
}
ll dfs2(int cur = 0, int pre = -1){
    ll res = !(ok[cur]);
    for(auto nxt: G[cur]){
        if(nxt == pre)continue;
        res += dfs2(nxt, cur);
    }
    return add[cur] = res;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    cin >> N >> K;
    G.resize(N);
    sz.assign(N, 0);
    d.resize(N);;
    rep(i,N-1){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs();
    rep(i,N)sz[i]--;
    //print(sz);
    //print(d);
    ok.assign(N, true);
    //d-szでソート
    vec<i_i> v;
    rep(i,N){
        v.push_back({d[i]-sz[i], i});
    }
    sort(all(v),greater<i_i>());
    //print(v);
    rep(i,K){
        ok[v[i].second] = false;
    }
    //print(ok);
    ll ans = 0;
    add.assign(N, 0);
    dfs2();
    rep(i,N){
        if(ok[i])ans += add[i];
    }
    cout << ans << endl;
}