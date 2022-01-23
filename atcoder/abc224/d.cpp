#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i, N) for(int i = 0; i < int(N); ++i)
#define rep1(i, N) for(int i = 1; i < int(N); ++i)
#define all(a) (a).begin(), (a).end()
#define bit(k) (1LL << (k))
#define SUM(v) accumulate(all(v), 0LL)

typedef pair<int, int> i_i;
typedef pair<ll, ll> l_l;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;
struct fast_ios {
    fast_ios() {
        cin.tie(0);
        ios::sync_with_stdio(false);
        cout << fixed << setprecision(20);
    };
} fast_ios_;

template <class T> inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}
template <class T> inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

#define TOSTRING(x) string(#x)
template <typename T> istream &operator>>(istream &is, vector<T> &vec) {
    for(T &x : vec)
        is >> x;
    return is;
}
template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) {
    os << "[";
    for(auto _ : v)
        os << _ << ", ";
    os << "]";
    return os;
};
template <typename T> ostream &operator<<(ostream &os, set<T> &st) {
    os << "(";
    for(auto _ : st) {
        os << _ << ", ";
    }
    os << ")";
    return os;
}
template <typename T> ostream &operator<<(ostream &os, multiset<T> &st) {
    os << "(";
    for(auto _ : st) {
        os << _ << ", ";
    }
    os << ")";
    return os;
}
template <typename T, typename U>
ostream &operator<<(ostream &os, const pair<T, U> &p) {
    os << "{" << p.first << ", " << p.second << "}";
    return os;
}
template <typename T, typename U>
ostream &operator<<(ostream &os, const map<T, U> &mp) {
    os << "[";
    for(auto _ : mp) {
        os << _ << ", ";
    }
    os << "]";
    return os;
}

#define DUMPOUT cerr
void dump_func() { DUMPOUT << endl; }
template <class Head, class... Tail>
void dump_func(Head &&head, Tail &&...tail) {
    DUMPOUT << head;
    if(sizeof...(Tail) > 0) {
        DUMPOUT << ", ";
    }
    dump_func(std::move(tail)...);
}

#ifdef DEBUG
#define dbg(...)                                                               \
    { dump_func(__VA_ARGS__) }
#define dump(...)                                                              \
    DUMPOUT << string(#__VA_ARGS__) << ": ";                                   \
    dump_func(__VA_ARGS__)
#else
#define dbg(...)
#define dump(...)
#endif

const int INF = (ll)1e9;
const ll INFLL = (ll)1e18 + 1;
const ll MOD = 1000000007;
// const ll MOD = 998244353;
const long double PI = acos(-1.0);

/*
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const string dir = "DRUL";
*/

int main() {
    int N = 9;
    vvec<int> G(N);

    int M;
    cin >> M;
    rep(i, M) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    vector<int> p(N - 1);
    vector<int> p_goal(N - 1);
    rep(i, N - 1) { p_goal[i] = i; }
    rep(j, N - 1) {
        cin >> p[j];
        p[j]--;
    }
    dump(p);
    dump(p_goal);
    map<vector<int>, int> visited;
    queue<pair<vector<int>, int>> q;
    q.push({p, 0});
    visited[p] = 1;

    dump(G);
    int ans = INF;
    while(!q.empty()) {
        auto [fromState, fromCnt] = q.front();
        q.pop();
        bool ok = true;
        rep(j,N-1){
            if(fromState[j]!=j){
                ok = false;
                break;
            }
        }
        if(ok){
            chmin(ans, fromCnt);
        }

        int empty = -1;
        int emptyCnt = 0;
        map<int, int> used;
        rep(j, N - 1) { used[fromState[j]] = 1; }
        rep(j, N) {
            if(not used[j]) {
                empty = j;
                emptyCnt++;
            }
        }
        assert(empty >= 0);
        assert(emptyCnt == 1);

        rep(j,N-1) {
            for(int nxt : G[fromState[j]]) {
                if(nxt != empty) {
                    continue;
                }
                vector<int> toState = fromState;
                //
                toState[j] = nxt;
                if(visited[toState]) {
                    continue;
                }
                q.push({toState, fromCnt + 1});
                visited[toState] = 1;
            }
        }
    }
    if(ans == INF) {
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
}