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

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const string dir = "DRUL";

struct UnionFind {
    int n;
    vector<int> Parent;
    vector<int> sizes;
    UnionFind(int _n) : n(_n), Parent(_n), sizes(_n, 1) {
        rep(i, n) Parent[i] = i;
    }
    // find the root of x
    int root(int x) {
        if(x != Parent[x]) {
            Parent[x] = root(Parent[x]);
        }
        return Parent[x];
    }
    // merge x and y
    void unite(int x, int y) {
        x = root(x);
        y = root(y);
        if(x == y)
            return;
        if(sizes[x] < sizes[y])
            swap(x, y);
        Parent[y] = x;
        sizes[x] += sizes[y];
    }
    bool same(int x, int y) { return root(x) == root(y); }
    int size(int x) { return sizes[root(x)]; }
    int group_num() {
        set<int> s;
        for(int i = 0; i < n; ++i) {
            s.insert(root(i));
        }
        return int(s.size());
    }
};

constexpr int H = 4;
constexpr int W = 4;
constexpr int N = 16;
int A[H][W];
int B[H][W];
int visited[H][W];
int main() {
    auto IsIn = [&](int i, int j) -> bool {
        return 0 <= i && i < H && 0 <= j && j < W;
    };
    auto f = [&](int i, int j) -> int { return i * W + j; };

    auto bfs = [&](int i, int j) -> bool {
        rep(i, H) rep(j, W) { visited[i][j] = 0; }
        queue<pair<int, int>> q;
        if(B[i][j] == 1) {
            return true;
        }
        q.push({i, j});
        visited[i][j] = 1;
        while(!q.empty()) {
            auto [x, y] = q.front();
            q.pop();
            rep(k, 4) {
                int nx = x + dx[k];
                int ny = y + dy[k];
                if(not IsIn(nx, ny)) {
                    return true;
                }
                if(B[nx][ny] == 1) {
                    continue;
                }
                if(visited[nx][ny]) {
                    continue;
                }
                visited[nx][ny] = 1;
                q.push({nx, ny});
            }
        }
        return false;
    };
    auto dumpB = [&]() {
        rep(i, H) {
            rep(j, W) { cerr << B[i][j] << " "; }
            cerr << endl;
        }
        cerr << endl;
    };

    vector<pair<int, int>> v;
    rep(i, H) rep(j, W) {
        cin >> A[i][j];
        if(A[i][j]) {
            v.emplace_back(i, j);
        }
    }
    // bit全探索
    int ans = 0;
    for(int mask = 0; mask < bit(N); mask++) {
        UnionFind T(N);
        rep(i, H) rep(j, W) { B[i][j] = 0; }
        int cnt = 0;
        for(int j = 0; j < N; j++) {
            if(bit(j) & mask) {
                // 塗られる場所
                int x = j / W;
                int y = j % W;
                B[x][y] = 1;
                cnt++;
            }
        }
        bool ok = true;
        for(auto [vx, vy] : v) {
            if(!B[vx][vy]) {
                ok = false;
            }
        }
        if(not ok) {
            continue;
        }

        // ぜんぶはいってる

        // 連結成分が1かどうか
        rep(i, H) rep(j, W) {
            if(!B[i][j]) {
                continue;
            }
            rep(k, 4) {
                int ni = i + dx[k];
                int nj = j + dy[k];
                if(not IsIn(ni, nj))
                    continue;
                if(B[ni][nj]) {
                    T.unite(f(i, j), f(ni, nj));
                }
            }
        }
        // 穴が空いているかどうかの判定 bfsして外に出れるかどうか
        for(int i = 1; i <= 2; i++) {
            for(int j = 1; j <= 2; j++) {
                if(!bfs(i, j)) {
                    ok = false;
                }
            }
        }
        if(not ok) {
            continue;
        }
        if(T.size(f(v[0].first, v[0].second)) == cnt) {
            // dumpB();
            ans++;
        }
    }
    cout << ans << endl;
}
