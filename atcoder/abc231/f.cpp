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

template <typename T> struct Compress {
    vector<T> xs;

    Compress() = default;

    Compress(const vector<T> &vs) { add(vs); }

    Compress(const initializer_list<vector<T>> &vs) {
        for(auto &p : vs)
            add(p);
    }

    void add(const vector<T> &vs) {
        copy(begin(vs), end(vs), back_inserter(xs));
    }

    void add(const T &x) { xs.emplace_back(x); }

    void build() {
        sort(begin(xs), end(xs));
        xs.erase(unique(begin(xs), end(xs)), end(xs));
    }

    vector<int> get(const vector<T> &vs) const {
        vector<int> ret;
        transform(begin(vs), end(vs), back_inserter(ret), [&](const T &x) {
            return lower_bound(begin(xs), end(xs), x) - begin(xs);
        });
        return ret;
    }

    int get(const T &x) const {
        return lower_bound(begin(xs), end(xs), x) - begin(xs);
    }

    const T &operator[](int k) const { return xs[k]; }
};

template <typename T> class BIT {
  public:
    int N;
    vector<T> data;
    BIT(T _N) : N(_N) { data.assign(N + 1, 0); };

    // a is 1-indexed
    void add(int a, T w) {
        for(int x = a; x <= N; x += x & -x)
            data[x] += w;
    }
    // 1-indexed sum of prefix [0, a]
    T sum(int a) {
        T res = 0;
        for(int x = a; x > 0; x -= x & -x)
            res += data[x];
        return res;
    }
    // 1-indexed sum of range [l, r]
    T sum(int l, int r) { return sum(r) - sum(l - 1); }

    // 0-indexed add
    void add0(int a, T w) { add(a + 1, w); }
    // 0-indexed sum
    T sum0(int a) { return sum(a + 1); }
    // 0-indexed sum of range
    T sum0(int l, int r) { 
        if(l == 0) {
            return sum0(r);
        }
        return sum0(r) - sum0(l - 1); }
    // show the value
    void debug() { dump(data); }
    // k-th number (k is 1 - indexed)
    T get(int k) {
        T res = 0;
        int sz = 1;
        while(sz < (int)data.size())
            sz <<= 1;
        for(int i = sz / 2; i > 0; i >>= 1) {
            if(res + i <= N && data[res + i] < k) {
                k -= data[res + i];
                res += i;
            }
        }
        return res + 1;
    }
};

int main() {
    int N;
    cin >> N;
    vector<int> A(N), B(N);
    vector<pair<int, int>> BA;
    map<pair<int, int>, ll> mp;
    rep(i, N) { cin >> A[i]; }
    rep(i, N) { cin >> B[i]; }
    rep(i, N) {
        BA.emplace_back(B[i], -A[i]);
        mp[BA.back()]++;
    }
    sort(all(BA));
    Compress<int> Comp;
    Comp.add(A);
    Comp.add(B);
    Comp.build();
    dump(Comp.xs);

    dump(BA);
    int M = 3 * N;
    BIT<ll> T(M);
    ll ans = 0;

    rep(i, N) {
        auto [d, c] = BA[i];
        int addIdx = Comp.get(-c);
        T.add0(addIdx, 1);
        ans += T.sum0(addIdx, M-1);
        dump(ans);
    }
    for(auto [_, cnt] : mp) {
        ans += cnt * (cnt - 1) / 2;
    }
    cout << ans << endl;

}
