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

const int MAXN = 100010;
vector<int> G[MAXN];
vector<ll> ans;
vector<ll> dpth;
vector<ll> visited;
vector<ll> val;
vector<ll> valcum;
vector<ll> l;
ll dfs1(int cur, int pre, int d){
    ll res = d * l[cur];
    visited[cur] = true;
    dpth[cur] = d;
    for(auto nxt: G[cur]){
        if(nxt == pre)continue;
        if(visited[nxt])continue;
        res += dfs1(nxt, cur, d+1);
    }
    return val[cur] = res;
}
ll dfs3(int cur, int pre){
    dump(cur, pre, valcum);
    ll res = l[cur];
    visited[cur] = true;
    for(auto nxt: G[cur]){
        if(nxt == pre)continue;
        if(visited[nxt])continue;
        res += dfs3(nxt, cur);
    }
    return valcum[cur] = res;
}
ll dfs2(int cur, int pre){

    ll tmp_cur = val[cur]; // 13
    ll tmp_valcum = valcum[cur];
    for(auto nxt: G[cur]){
        tmp_cur -= val[nxt]; // 13 - 2 = 11
        val[nxt] += tmp_cur + tmp_cur;
    }
}
int main() {
    int N;
    cin >> N;
    l.resize(N);
    rep(i,N)cin >> l[i];
    rep(i,N-1){
        int a, b;
        cin >> a >> b;
        a--, b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    ans.resize(N);
    dpth.resize(N);
    val.resize(N);
    valcum.resize(N,0);
    /* calc */

    // まず根付き木をdfs1してans[0]を求める
    visited.assign(N, false);
    dfs1(0, -1, 0);
    visited.assign(N, false);
    dfs3(0, -1);
    dump(dpth);
    dump(val);
    dump(valcum);
    /*      */
    ans[0] = ans[0];
    // dfs2(0, -1);
    rep(i,N){
        cout << ans[i] << endl;
    }
}
