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
// const ll MOD = 1000000007;
const ll MOD = 998244353;
const long double PI = acos(-1.0);

/*
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const string dir = "DRUL";
*/

struct mint {
    long long x;
    mint(long long _x = 0) : x((_x % MOD + MOD) % MOD) {}
    mint operator-() const { return mint(-x); }
    mint &operator+=(const mint a) {
        if((x += a.x) >= MOD)
            x -= MOD;
        return *this;
    }
    mint &operator-=(const mint a) {
        if((x += MOD - a.x) >= MOD)
            x -= MOD;
        return *this;
    }
    mint &operator*=(const mint a) {
        (x *= a.x) %= MOD;
        return *this;
    }
    mint operator+(const mint a) const {
        mint res(*this);
        return res += a;
    }
    mint operator-(const mint a) const {
        mint res(*this);
        return res -= a;
    }
    mint operator*(const mint a) const {
        mint res(*this);
        return res *= a;
    }
    mint modpow(long long t) const {
        if(!t)
            return 1;
        mint a = modpow(t >> 1);
        a *= a;
        if(t & 1)
            a *= *this;
        return a;
    }
    // for prime MOD
    mint inv() const { return modpow(MOD - 2); }
    mint &operator/=(const mint a) { return (*this) *= a.inv(); }
    mint operator/(const mint a) const {
        mint res(*this);
        return res /= a;
    }
    friend std::ostream &operator<<(std::ostream &os, const mint &a) {
        os << a.x;
        return os;
    }
};

int main() {
    int N, M;
    cin >> N >> M;
    vector<pair<int, int>> edges;
    rep(i, M) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        edges.emplace_back(u, v);
    }

    mint ans = 0;
    for(int mask = 0; mask < bit(M); mask++) {
        vvec<int> G(N);
        rep(j, M) {
            auto [u, v] = edges[j];
            if(bit(j) & mask) {
                G[u].push_back(v);
            } else {
                G[v].push_back(u);
            }
        }
        bool ok = true;
        rep(i, N) {
            if(G[i].size() != 1) {
                ok = false;
            }
        }
        if(ok) {
            ans += 1;
            dump(G);
        }
    }
    cout << ans << endl;
}

/*
頂点を分類する

サイクルを構成する頂点。複数のサイクルに所属してはならない。
サイクル上にあり、他のサイクルとつながるような頂点
サイクル上にはない頂点。
*/