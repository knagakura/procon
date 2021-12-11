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
    T sum0(int l, int r) { return sum0(r) - sum0(l - 1); }
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
    string S;
    int K;
    cin >> S >> K;
    ll N = S.size();
    BIT<ll> T(N);
    rep(i, N) { T.add0(i, S[i] == '.'); }

    // 連続でx個連続にできるか
    auto check = [&](ll x) -> bool {
        dump(x);
        // 連続でx個の和がK以下
        for(int i = 0; i < N - x + 1; i++) {
            int cnt = T.sum0(i, i + x - 1);
            dump(i, i + x - 1, cnt);
            if(cnt <= K) {
                return true;
            }
        }
        return false;
    };
    ll ok = 0;
    ll ng = N + 1;
    while(ng - ok > 1) {
        ll mid = (ok + ng) / 2;
        if(check(mid)) {
            ok = mid;
        } else {
            ng = mid;
        }
    }
    cout << ok << endl;
}
