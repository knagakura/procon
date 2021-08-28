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
constexpr double TL = 2;
long long CYCLES_PER_SEC = 2800000000;
struct MyTimer {
    long long start;
    MyTimer() { reset(); }

    void reset() { start = getCycle(); }
    inline double get() {
        return (double)(getCycle() - start) / CYCLES_PER_SEC;
    }

    inline long long getCycle() {
        unsigned low, high;
        __asm__ volatile("rdtsc" : "=a"(low), "=d"(high));
        return ((long long)low) | ((long long)high << 32);
    }
} aMyTimer;

ll dp[5000][5000];
pair<int, int> pdp[5000][5000];

class MSA {
  public:
    pair<vector<int>, vector<int>> getPairwiseAlignment(const vector<int> &S,
                                              const vector<int> &T) {
        return _getPairwiseAlignment(S, T, true);
    }

    /*
     * '-'を含む最長の文字列Lに対して、L側はスキップすることを許さない方法でアラインメントを求める
     *
     */
    vector<int> getPairwiseAlignmentCannotSkip(const vector<int> &L, const vector<int> &S) {
        auto [l, res] = _getPairwiseAlignment(L, S, false);
        dump(l.size(), L.size());
        assert(l.size() == L.size());
        return res;
    }

  private:
    pair<vector<int>, vector<int>> _getPairwiseAlignment(const vector<int> &S, const vector<int> &T,
                                               bool canSkip) {
        int N = S.size();
        int M = T.size();
        rep(i, N + 1) rep(j, M + 1) {
            dp[i][j] = -INF;
            pdp[i][j] = {-1, -1};
        }
        dp[0][0] = 0;
        pdp[0][0] = {-1, -1};
        rep(i, N + 1) {
            rep(j, M + 1) {
                if(chmax(dp[i + 1][j], dp[i][j] - 5)) {
                    pdp[i + 1][j] = {i, j};
                }
                if(canSkip && chmax(dp[i][j + 1], dp[i][j] - 5)) {
                    pdp[i][j + 1] = {i, j};
                }
                if(S[i] == T[j]) {
                    if(chmax(dp[i + 1][j + 1],
                             dp[i][j] + (canSkip ? 10000 : 1))) {
                        pdp[i + 1][j + 1] = {i, j};
                    }
                } else {
                    if(chmax(dp[i + 1][j + 1], dp[i][j] - 3)) {
                        pdp[i + 1][j + 1] = {i, j};
                    }
                }
            }
        }
        // 復元
        vector<int> ans1;
        vector<int> ans2;
        int x = N;
        int y = M;
        while(true) {
            if(x == 0 && y == 0)
                break;
            auto [px, py] = pdp[x][y];
            if(x - 1 == px && y - 1 == py) {
                ans1.push_back(S[x - 1]);
                ans2.push_back(T[y - 1]);
            } else if(x == px && y - 1 == py) {
                ans1.push_back(4);
                ans2.push_back(T[y - 1]);
            } else if(x - 1 == px && y == py) {
                ans1.push_back(S[x - 1]);
                ans2.push_back(4);
            } else {
                assert(false);
            }
            x = px, y = py;
        }
        reverse(all(ans1));
        reverse(all(ans2));
        assert(ans1.size() == ans2.size());
        return {ans1, ans2};
    }
} aMSA;

vector<int> convert2Vec(const string &S) {
    vector<int> v;
    for(auto &c : S) {
        if(c == 'A') {
            v.push_back(0);
        } else if(c == 'T') {
            v.push_back(1);
        } else if(c == 'G') {
            v.push_back(2);
        } else if(c == 'C') {
            v.push_back(3);
        } else if(c == '-') {
            v.push_back(4);
        } else {
            assert(false);
        }
    }
    return v;
}

const string genome = "ATGC-";
string convert2String(const vector<int> &v) {
    string S;
    for(auto &val : v) {
        S.push_back(genome[val]);
    }
    return S;
}

int main() {
    int M;
    cin >> M;
    vector<string> S(M);
    vector<int> sz(M);
    vector<pair<int, pair<int, vector<int>>>> szS;
    rep(i, M) {
        cin >> S[i];
        sz[i] = S[i].size();
        szS.push_back({sz[i], {i, convert2Vec(S[i])}});
    }
    sort(all(szS));
    int N = szS.back().first;

    // aMyTimer.reset();
    vector<vector<int>> ans(M);
    vector<int> gen = szS[M-1].second.second;
    while(aMyTimer.get() < TL) {
        rep(i, M) {
            auto [idx, str] = szS[i].second;
            auto [l, r] = aMSA.getPairwiseAlignment(gen, str);
            ans[idx] = r;
            if(gen.size() < l.size()){
                dump("swap");
                swap(gen, l);
            }
            if(gen != l){
                dump(i, aMyTimer.get());
            }
        }
    }
    rep(i, M) {
        auto [idx, str] = szS[i].second;
        ans[idx] = aMSA.getPairwiseAlignmentCannotSkip(gen, str);
    }
    for(vector<int> &_ans : ans) {
        cout << convert2String(_ans) << endl;
    }
}
