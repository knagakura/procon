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
template <typename T, typename U> ostream &operator<<(ostream &os, const pair< T, U >& p){os << "{" <<p.first << ", " << p.second << "}";return os; }
template <typename T, typename U> ostream &operator<<(ostream &os, const map<T, U> &mp){ os << "["; for(auto _: mp){ os << _ << ", "; } os << "]" << endl; return os; }

#define DUMPOUT cerr
void dump_func(){ DUMPOUT << endl; }
template <class Head, class... Tail> void dump_func(Head &&head, Tail &&... tail) { DUMPOUT << head; if (sizeof...(Tail) > 0) { DUMPOUT << ", "; } dump_func(std::move(tail)...); }

#ifdef DEBUG
#define dbg(...) dump_func(__VA_ARGS__)
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

/*
@title 抽象化セグ木
@category データ構造
*/
template<typename T>
class SegTree {
  public:
    int N;//葉の数
    vector<T> data;//配列
    T unit;//単位元
    function<T(T,T)> op;//区間クエリで使う処理
    function<T(T,T)> update;//点更新で使う処理
    T _query(int a, int b, int k, int l, int r) {
        if(r <= a || b <= l)return unit;
        if(a <= l && r <= b){
            return data[k];
        }
        else{
            T c1 = _query(a, b, 2 * k + 1, l, (l + r) / 2); //左の子
            T c2 = _query(a, b, 2 * k + 2, (l + r) / 2, r); //左の子
            return op(c1, c2);
        }
    }
    //コンストラクター
    //_N: 必要サイズ, _unit: 初期値かつ単位元, _op: クエリ関数, _update: 更新関数
    SegTree(int _N, T _unit, function<T(T, T)> _op, function<T(T, T)> _update) 
        :unit(_unit), op(_op), update(_update){
        N = 1;
        while(N < _N)N *= 2;
        data.assign(2 * N - 1, unit);
    }
    //i(0-indexed)の値にupdate関数を適用
    void change(int i, T x){
        i += N - 1;
        data[i] = update(data[i], x);
        while(i > 0){
            i = (i - 1) / 2;
            data[i] = op(data[i * 2 + 1], data[i * 2 + 2]);
        }
    }
    //[a, b)の区間クエリの実行
    T query(int a, int b){
        return _query(a, b, 0, 0, N);
    }
    //添字でアクセス
    T operator[](int i) {
        return data[i + N - 1];
    }
};

int main() {
    int N;
    cin >> N;
    vector<ll> a(N);
    rep(i,N){
        cin >> a[i];
        a[i]--;
    }
    auto f = [&](long long a, long long b){
        return max(a, b);
    };
    auto g = [&](long long a, long long b){
        return b;
    };
    SegTree<long long> Tree(N,0,f,g);
    ll ans = 0;
    rep(i,N){
        ll cnt = Tree.query(0, a[i]) + 1;
        chmax(ans, cnt);
        Tree.change(a[i], cnt);
    }
    cout << ans << endl;
}
