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
    int N, M;
    cin >> N >> M;
    vvec<int> G(N);
    vector<pair<int, int>> st;
    vector<int> dist(N, INF);
    vector<int> pre(N, -1);
    rep(i, M) {
        int s, t;
        cin >> s >> t;
        s--, t--;
        st.emplace_back(s, t);
        G[s].push_back(t);
    }
    std::queue<int> q;
    q.push(0);
    dist[0] = 0;
    while(!q.empty()) {
        int v = q.front();
        q.pop();
        for(auto n : G[v]) {
            if(dist[n] != INF)
                continue;
            dist[n] = dist[v] + 1;
            pre[n] = v;
            q.push(n);
        }
    }
    if(dist[N - 1] == INF) {
        rep(i, M) { cout << -1 << endl; }
        return 0;
    }
    int v = N - 1;
    vector<pair<int, int>> tour;
    map<pair<int, int>, int> mp;
    while(v != 0) {
        tour.push_back({pre[v], v});
        mp[tour.back()]++;
        v = pre[v];
    }
    rep(i, M) {
        auto [s, t] = st[i];
        if(mp[{s, t}]) {
            // 計算し直し
            vector<int> dist2(N, INF);
            std::queue<int> q2;
            q2.push(0);
            dist2[0] = 0;
            while(!q2.empty()) {
                int v = q2.front();
                q2.pop();
                for(auto n : G[v]) {
                    if(dist2[n] != INF)
                        continue;
                    if(v == s && n == t)continue;
                    dist2[n] = dist2[v] + 1;
                    q2.push(n);
                }
            }
            cout << (dist2[N-1] == INF ? -1: dist2[N-1]) << endl;
        } else {
            cout << dist[N - 1] << endl;
        }
    }
}
