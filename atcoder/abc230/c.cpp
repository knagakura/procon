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

    ll N, A, B;
    ll P, Q, R, S;
    cin >> N >> A >> B;
    cin >> P >> Q >> R >> S;

// #ifdef DEBUG
//     char f[N][N];
//     rep(i, N) rep(j, N) f[i][j] = '.';
//     {
//         ll l = max(1 - A, 1 - B), r = min(N - A, N - B);
//         for(ll k = l; k <= r; k++) {
//             f[A + k - 1][B + k - 1] = '#';
//         }
//     }
//     {
//         ll l = max(1 - A, B - N), r = min(N - A, B - 1);
//         for(ll k = l; k <= r; k++) {
//             f[A + k - 1][B - k - 1] = '#';
//         }
//     }
//     rep(i, N) {
//         rep(j, N) { cerr << f[i][j]; }
//         cerr << endl;
//     }
//     //
// #endif
    for(ll i = P; i <= Q; i++) {
        for(ll j = R; j <= S; j++) {
            if(abs(i - A) == abs(j - B)) {
                cout << "#";
            }else {
                cout << ".";
            }
        }
        cout << endl;
    }
    cout << endl;
}