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
const ll INFLL = (ll)9223372036854775807;
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


ll N;
ll calcCnt(ll x){
    ll oka = 0;
    ll nga = max(ll(2), min(ll(sqrt(N)), x + 1));
    while(abs(oka - nga) > 1) {
        ll a = (oka + nga) / 2;
        if((2 * x - a) <= N/a) {
            oka = a;
        } else {
            nga = a;
        }
    }
    return oka;
}

int main() {
    cin >> N;
    mint ans = 0;
    ll x = 1;
    for(x = 1; x * x <= N; x++){
        ans += x;
    }

    dump(x);
    while(x < N) {
        // 2 * x * a - a <= Nを満たす最大のa(1 <= a <= x)が個数になる
        // 個数は連続しているので、その個数がいくつ連続するかで場合分けしていけば、区間の個数はO(N)なので探索が終わる気がする

        // 区間の左端がxのときの個数の値を求めます O(log(x))

        ll cnt = calcCnt(x);

        // このokaと同じになる右端はどこですか？
        ll okx = x;
        ll ngx = N;

        while(abs(ngx - okx) > 1){
            ll midx = (ngx + okx) / 2;
            ll tmpCnt = calcCnt(midx);
            if(tmpCnt < cnt){
                ngx = midx;
            }
            else {
                okx = midx;
            }
        }
        ans += mint((ngx - x)) * mint(cnt);
        x = ngx;
    }
    cout << ans << endl;
}
