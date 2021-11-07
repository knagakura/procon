
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
template <typename T> ostream &operator<<(ostream &os, multiset<T> &st) { os << "("; for(auto _: st) { os << _ << ", "; } os << ")";return os;}
template <typename T, typename U> ostream &operator<<(ostream &os, const pair< T, U >& p){os << "{" <<p.first << ", " << p.second << "}";return os; }
template <typename T, typename U> ostream &operator<<(ostream &os, const map<T, U> &mp){ os << "["; for(auto _: mp){ os << _ << ", "; } os << "]"; return os; }

#define DUMPOUT cerr
void dump_func(){ DUMPOUT << endl; }
template <class Head, class... Tail> void dump_func(Head &&head, Tail &&... tail) { DUMPOUT << head; if (sizeof...(Tail) > 0) { DUMPOUT << ", "; } dump_func(std::move(tail)...); }

#ifdef DEBUG
#define dbg(...) { dump_func(__VA_ARGS__) }
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

class Solution {
public:
    // TIME COMPLEXITY:- O(N)
    // SPACE COMPLEXITY:- O(N)
    ll dfs(int v,int par, const vvec<int> &adj,vector<ll>& subtree){
        ll curr = 0;
        for(auto u:adj[v]){
            if(u!=par){
                curr+=dfs(u,v,adj,subtree);
                curr+=subtree[u];
                subtree[v]+=subtree[u];
            }
        }
        return curr;
    }
    void dfs(int v,int par,const vvec<int> &adj,vector<ll>& ans,vector<ll>& subtree,ll now){
        ans[v] = now;
        for(auto u:adj[v]){
            if(u!=par)
                dfs(u,v,adj,ans,subtree,now-subtree[u]+subtree[0]-subtree[u]);
        }
    }
    vector<ll> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
        vector<ll> ans(n),subtree(n,1);
        vvec<int> adj;
        adj.resize(n);
        for(auto v:edges){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        ll root_ans = dfs(0,-1,adj,subtree);
        dfs(0,-1,adj,ans,subtree,root_ans);
        return ans;
    }
};

int main(){
    int N;
    cin >> N;
    vvec<int> edges;
    rep(i,N-1){
        int u, v;
        cin >> u >> v;
        u--, v--;
        edges.push_back({u, v});
    }
    Solution sol;
    auto ans = sol.sumOfDistancesInTree(N, edges);
    for(auto a: ans){
        cout << a << endl;
    }
}