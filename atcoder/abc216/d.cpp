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

int N, M;
vvec<int> a;
vector<i_i> v0, v1;
vector<int> top;
vector<bool> done;
vector<int> tryed;

bool dfs(int i) {
    dump(i);
    if(done[i]) {
        return true;
    }
    tryed[i]++;
    if(tryed[i] == 3){
        return false;
    }
    auto [j0, k0] = v0[i];
    auto [j1, k1] = v1[i];
    if(top[j0] == k0 && top[j1] == k1) {
        top[j0]++;
        top[j1]++;
        done[i] = true;
        return true;
    } else {
        if(top[j0] != k0){
            bool f1 = dfs(a[j0][top[j0]]);
            if(!f1){
                return false;
            }
        }
        if(top[j1] != k0){
            bool f2 = dfs(a[j1][top[j1]]);
            if(!f2){
                return false;
            }
        }
    }
    return true;
}
int main() {
    cin >> N >> M;
    a.resize(M);
    v0.assign(N, {-1, -1});
    v1.assign(N, {-1, -1});
    rep(j, M) {
        int K;
        cin >> K;
        a[j].resize(K);
        rep(k, K) {
            cin >> a[j][k];
            a[j][k]--;
            if(v0[a[j][k]].first == -1) {
                v0[a[j][k]] = {j, k};
            } else {
                v1[a[j][k]] = {j, k};
            }
        }
        dump(a[j]);
    }
    dump(v0);
    dump(v1);
    rep(i,N){
        auto [j0, k0] = v0[i];
        auto [j1, k1] = v1[i];
        if(j0 == j1){
            cout << "No" << endl;
            return 0;
        }
    }

    // j番目の筒の先頭の座標

    top.assign(M, 0);
    done.assign(M, false);
    tryed.assign(N, 0);
    // まず、色0をやりたいです。
    // 再帰関数で実装できそう
    rep(i, N) {
        if(done[i]) {
            continue;
        }
        bool isOk = dfs(i);
        if(not isOk){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}
