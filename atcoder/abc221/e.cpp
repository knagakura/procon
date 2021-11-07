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

class BIT {
  public:
    int N;
    vector<mint> data;
    BIT(int _N) : N(_N) { data.assign(N + 1, 0); };

    // a is 1-indexed
    void add(int a, mint w) {
        for(int x = a; x <= N; x += x & -x)
            data[x] += w;
    }
    // 1-indexed sum of prefix [0, a]
    mint sum(int a) {
        mint res = 0;
        for(int x = a; x > 0; x -= x & -x)
            res += data[x];
        return res;
    }
    // 1-indexed sum of range [l, r]
    mint sum(int l, int r) { return sum(r) - sum(l - 1); }

    // 0-indexed add
    void add0(int a, mint w) { add(a + 1, w); }
    // 0-indexed sum
    mint sum0(int a) { return sum(a + 1); }
    // 0-indexed sum of range
    mint sum0(int l, int r) { return sum0(r) - sum0(l - 1); }
    // show the value
    void debug() { dump(data); }
};

template <typename T> struct Compress {
    vector<T> v;
    Compress() {}
    Compress(vector<T> _v) : v(_v) { build(); }

    void add(T x) { v.emplace_back(x); }

    void build() {
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
    }
    void build(vector<T> _v) {
        v = _v;
        sort(v.begin(), v.end());
        v.erase(unique(v.begin(), v.end()), v.end());
    }
    int get(T x) { return lower_bound(v.begin(), v.end(), x) - v.begin(); }

    T &operator[](int i) { return v[i]; }

    int size() { return (int)v.size(); }
};

/*
indexを後ろから見て、
自分より後ろに、自分以上のものがいくつあるかを高速に数えれば良い
*/
int main() {
    int N;
    cin >> N;
    vector<ll> A(N);
    Compress<ll> C;
    map<ll, int> idxmap;
    vector<pair<ll, int>> sorted_A;
    rep(i, N) {
        cin >> A[i];
        sorted_A.emplace_back(A[i], i);
        C.add(A[i]);
    }
    sort(all(sorted_A));
    rep(i, N) { idxmap[sorted_A[i].second] = i; }
    C.build();
    mint ans = 0;
    BIT T(N);
    dump(A);
    multiset<pair<int, int>> st;
    for(int i = N - 1; i >= 0; i--) {
        // int idx = C.get(A[i]);
        int idx = idxmap[i];
        // int cnt = T.sum0(idx, N-1);
        if(!st.empty()) {
            int cnt = max(0, (*st.rbegin()).second - i);
            dump(st);
            dump(idx, cnt);
            ans += mint(2).modpow(cnt) - 1;
        }
        T.add0(idx, 1);
        st.insert({idx, i});
    }
    cout << ans << endl;
}
/*
830 - (2^8 - 1 + 2^8  -1 + 2^1 - 1 + 2^6-1)
*/
