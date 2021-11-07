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

vvec<int> G;
vec<int> cnt;
vector<int> visited;

bool dfs(int v, int p){
    dump(p, v);
    bool res = false;
    visited[v]++;
    for(auto &nv: G[v]){
        if(visited[nv]){
            res |= true;
        }
        if(res){
            dump(p, v, nv);
            break;
        }
        res |= dfs(nv, v);
    }
    return res;
}

int main() {
    int N, M;
    cin >> N >> M;
    G.resize(N);
    cnt.assign(N, 0);
    visited.assign(N, 0);
    map<pair<int, int>, int> mp;
    rep(i,M){
        int a, b;
        cin >> a >> b;
        a--, b--;
        if(mp.count({a, b})){
            continue;
        }
        mp[{a, b}]++;
        dump(a,b);
        G[a].push_back(b);
        cnt[b]++;
    }
    dump(G);
    // bool cycle = false;

    // rep(i,N){
    //     if(cnt[i] == 0 && G[i].size() > 0 && not visited[i]){
    //         visited.assign(N, 0);
    //         cycle |= dfs(i, -1);
    //     }
    // }

    // if(cycle){
    //     cout << -1 << endl;
    //     return 0;
    // }

    // stack<int> st;
    priority_queue<int, vector<int>, greater<int>> st;
    rep(i,N){
        if(cnt[i] == 0 && G[i].size() > 0){
            st.push(i);
        }
        else if(cnt[i] == 0){
            st.push(i);
        }
    }

    // サイクルがあるから無理
    if(st.empty()){
        cout <<  -1 << endl;
        return 0;
    }

    vector<int> ans;
    priority_queue<int, vector<int>, greater<int>> pq;
    while(!st.empty()){
        int i = st.top();
        dump(i);
        st.pop();
        ans.push_back(i);
        for(auto &j: G[i]){
            cnt[j]--;
            if(cnt[j] == 0){
                st.push(j);
            }
            if(cnt[j] < 0){
                cout << -1 << endl;
                return 0;
            }
        }
    }
    dump(cnt);
    if(SUM(cnt)){
        cout << -1 << endl;
        return 0;
    }
    // 

    dump(ans);
    rep(i,N){
        cout << ans[i]+1 << " ";
    }
    cout << endl;
}
