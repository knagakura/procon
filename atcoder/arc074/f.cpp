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
template<typename T>
struct edge{
    int to;
    T cap;
    int rev;
};
template<typename T>
struct FordFulkerson{
    int V;
    vector<vector<edge<T>>> G;
    vector<bool> used;
    T inf;
    FordFulkerson(int V_, T inf_):V(V_), inf(inf_){
        G.resize(V);
        used.assign(V, false);
    }
    void add_edge(int from, int to, T cap){
        G[from].push_back((edge<T>){to, cap, (int)G[to].size()});
        G[to].push_back((edge<T>){from, 0, (int)G[from].size()-1});
    }
    T dfs(int v, int t, T f){
        if(v == t)return f;
        used[v] = true;
        for(auto &&e: G[v]){
            if(used[e.to])continue;
            if(e.cap <= 0)continue;
            int d = dfs(e.to, t, min(f, e.cap));
            if(d > 0){
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
        return 0;
    }
    T max_flow(int s, int t){
        T flow = 0;
        for( ; ; ){
            used.assign(V, false);
            int f = dfs(s, t, INF);
            if(f == 0)return flow;
            flow += f;
        }
    }
};


int main() {
    int H, W;
    cin >> H >> W;
    vector<string> a(H);
    cin >> a;
    auto f = [&](int x, int y){
        return x * W + y;
    };
    vvec<int> S(H), T(W);
    int s = 0, t = 0;
    rep(i,H){
        rep(j,W){
            if(a[i][j] == 'S')s = f(i, j);
            if(a[i][j] == 'T')t = f(i, j);
            if(a[i][j] != '.')S[i].push_back(f(i,j));
        }
    }
    rep(j,W){
        rep(i,H){
            if(a[i][j] != '.')T[j].push_back(f(i,j));
        }
    }
    dump(s, t);
    if(s%W == t%W || s/W == t/W){
        cout << -1 << endl;
        return 0;
    }
    rep(i,H){
        dump(S[i]);
    }
    rep(j,W){
        dump(T[j]);
    }
    FordFulkerson<ll> G(H*W, INFLL);
    rep(i,H){
        rep(j,S[i].size()){
            rep(k,S[i].size()){
                G.add_edge(S[i][j], S[i][k], INF);
            }
        }
    }
    rep(i,W){
        rep(j,T[i].size()){
            rep(k,T[i].size()){
                G.add_edge(T[i][j], T[i][k], INF);
            }
        }
    }
    cout << G.max_flow(s, t) << endl;
}

