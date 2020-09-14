#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define bit(k) (1LL<<(k))
#define SUM(v) accumulate(all(v), 0LL)

typedef pair<int, int> i_i;
typedef pair<ll, ll> l_l;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;
struct fast_ios{ fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; }fast_ios_;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

#define TOSTRING(x) string(#x)
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (T &x : vec) is >> x; return is; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) { os  << "["; for(auto _: v) os << _ << ", "; os << "]"; return os; };
template <typename T> ostream &operator<<(ostream &os, set<T> &st) { os << "("; for(auto _: st) { os << _ << ", "; } os << ")";return os;}
template <typename T, typename U> ostream &operator<<(ostream &os, const pair< T, U >& p){os << "{" <<p.first << ", " << p.second << "}";return os; }
template <typename T, typename U> ostream &operator<<(ostream &os, const map<T, U> &mp){ os << "["; for(auto _: mp){ os << _ << ", "; } os << "]" << endl; return os; }

#define DUMPOUT cerr
void dump_func(){ DUMPOUT << endl; }
template <class Head, class... Tail> void dump_func(Head &&head, Tail &&... tail) { DUMPOUT << head; if (sizeof...(Tail) > 0) { DUMPOUT << ", "; } dump_func(std::move(tail)...); }

#ifdef DEBUG
#define dbg(...) dump_func(__VA_ARGS__)
#define dump(...) DUMPOUT << string(#__VA_ARGS__) << ": "; dump_func(__VA_ARGS__)
#else
#define dbg(...)
#define dump(...)
#endif

const int INF = (ll)1e9;
const ll INFLL = (ll)1e18+1;
const ll MOD = 1000000007;
// const ll MOD = 998244353;
const long double PI = acos(-1.0);

/*
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const string dir = "DRUL";
*/

vvec<int> G;
vec<int> dp,dp2;
int dfs1(int cur, int pre){
    int res = 1;
    for(int nxt: G[cur]){
        if(nxt == pre)continue;
        res += dfs1(nxt, cur);
    }
    return dp[cur] = res;
}

void dfs2(int cur, int pre){
    int maxx = 0;
    // curが根のときのcal
    for(int nxt: G[cur])chmax(maxx, dp[nxt]);
    dp2[cur] = maxx;
    // 潜りながらrerooting
    int tmp_dp_cur = dp[cur];
    for(int nxt: G[cur]){
        if(nxt == pre)continue;
        int tmp_dp_nxt = dp[nxt];
        // rerootingして潜る
        dp[cur] -= tmp_dp_nxt;
        dp[nxt] += dp[cur];
        dfs2(nxt, cur);
        // 戻す
        dp[cur] = tmp_dp_cur;
        dp[nxt] = tmp_dp_nxt;
    }
}
void solve(){
    int N;
    cin >> N;
    G.resize(N);
    dp.resize(N);
    dp2.resize(N);
    rep(i,N-1){
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].emplace_back(b);
        G[b].emplace_back(a);
    }
    // dp[i] : = 0をrootとして、頂点i以下にいくつ頂点があるか
    dfs1(0, -1);
    dump(dp);
    // ある頂点iを除いたときのconnected componentのサイズのmax
    dfs2(0, -1);
    dump(dp2);
    vector<int> centroids;
    int minn = *min_element(all(dp2));
    rep(i,N){
        if(minn == dp2[i])centroids.emplace_back(i);
    }
    int cnt = centroids.size();
    // centroidの個数が一個だけ
    if(cnt == 1){
        cout << 1 << " " << G[0][0]+1 << endl;
        cout << 1 << " " << G[0][0]+1 << endl;
        return;
    }
    // centroidが複数ある => 多分2個しかない
    int a = centroids[0];
    int b = centroids[1];
    int idx = 0;
    if(G[a][idx] == b)idx++;
    cout << a + 1 << " " << G[a][idx] + 1 << endl;
    cout << b + 1 << " " << G[a][idx] + 1 << endl;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        solve();
        G.clear();
        dp.clear();
        dp2.clear();
    }
}
