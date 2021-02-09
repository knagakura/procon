#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define bit(k) (1LL<<(k))
#define SUM(v) accumulate(all(v), 0LL)

typedef pair<int, int> i_i;
typedef pair<ll, ll> l_l;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;
struct fast_ios{ fast_ios(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20); }; }fast_ios_;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

#define TOSTRING(x) string(#x)
template <typename T> istream &operator>>(istream &is, vector<T> &vec) { for (T &x : vec) is >> x; return is; }
template <typename T> ostream &operator<<(ostream &os, const vector<T> &v) { os  << "["; for(auto _: v) os << _ << ", "; os << "]"; return os; };
template <typename T> ostream &operator<<(ostream &os, set<T> &st) { os << "("; for(auto _: st) { os << _ << ", "; } os << ")";return os;}
template <typename T> ostream &operator<<(ostream &os, multiset<T> &st) { os << "("; for(auto _: st) { os << _ << ", "; } os << ")";return os;}
template <typename T, typename U> ostream &operator<<(ostream &os, const pair< T, U >& p){os << "{" <<p.first << ", " << p.second << "}";return os; }
template <typename T, typename U> ostream &operator<<(ostream &os, const map<T, U> &mp){ os << "["; for(auto _: mp){ os << _ << ", "; } os << "]" << endl; return os; }

#define DUMPOUT cerr
void dump_func(){ DUMPOUT << endl; }
template <class Head, class... Tail> void dump_func(Head &&head, Tail &&... tail) { DUMPOUT << head; if (sizeof...(Tail) > 0) { DUMPOUT << ", "; } dump_func(std::move(tail)...); }

#ifdef DEBUG
#define dbg(...) { dump_func(__VA_ARGS__) }
#define dump(...) DUMPOUT << string(#__VA_ARGS__) << ": "; dump_func(__VA_ARGS__)
#else
#define dbg(...)
#define dump(...)
#endif

const int INF = (ll)1e9;
const ll INFLL = (ll)1e18+1;
const ll MOD = 1000000007;
// const ll MOD = 998244353;
const long double PI = acos(-1.0);

/*
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const string dir = "DRUL";
*/

template<typename T>
class BIT{
  public:
    int N;
    vector<T> data;
    BIT(T _N):N(_N){
        data.assign(N+1, 0);
    };
    
    // a is 1-indexed
    void add(int a, T w){
        for(int x = a; x <= N; x += x & -x)data[x] += w;
    }
    // 1-indexed sum of prefix [0, a]
    T sum(int a){
        T res = 0;
        for(int x = a; x > 0; x -= x & -x)res += data[x];
        return res;
    }
    // 1-indexed sum of range [l, r]
    T sum(int l, int r){return sum(r) - sum(l-1);}

    // 0-indexed add
    void add0(int a, T w){add(a + 1, w);}
    // 0-indexed sum
    T sum0(int a){return sum(a + 1);}
    // 0-indexed sum of range
    T sum0(int l, int r){return sum0(r) - sum0(l-1);}
    // show the value
    void debug(){print(data);}
};

ll tento(const vector<int> & a){
    int N = a.size();
    vector<ll> b(N);
    vector<pair<ll, int>> ap;
    rep(i,N){
        ap.push_back(make_pair(a[i], i));
    }
    sort(ap.begin(), ap.end());
    rep(i,N)b[ap[i].second] = i;
    BIT<long long> c(N);
    ll ans = 0;
    rep(i,N){
        ans += i - c.sum0(b[i]);
        c.add0(b[i], 1);
    }
    return ans;
}
const ll modd = 1e9;
int main() {
    int K;
    cin >> K;
    vector<vector<int>> a(K);
    vector<map<ll, ll>> mps(K);
    rep(i,K){
        int n;
        cin >> n;
        a[i].resize(n);
        cin >> a[i];
        rep(j, n){
            mps[i][a[i][j]]++;
        }
    }
    vector<ll> tentosu(K, 0);
    rep(i,K){
        tentosu[i] = tento(a[i]);
    }
    dump(tentosu);
    int q;
    cin >> q;
    vector<int> b(q);
    rep(i,q){
        cin >> b[i];
        b[i]--;
    }
    ll ans = 0;
    map<ll, ll> mpall;
    rep(i,q){
        // その数列内部の転倒数
        ans += tentosu[b[i]];
        ans %= modd;
        for(auto [val, cnt]: mps[b[i]]){
            // valより大きいのがいくつあるか
            for(auto [valall,cntall]: mpall){
                if(valall > val){
                    ans += cnt * cntall;
                    ans %= modd;
                }
            }
        }
        for(auto p: mps[b[i]]){
            mpall[p.first] += p.second;
        }
        dump(ans);
    }
    cout << ans % modd << endl;
}
