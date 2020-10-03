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

/* compress
    (X1,Y1),(X2,Y2)という二点で表されるもの（長方形や直線など）について、行か列の片方（X1とX2 or Y1とY2）を座標圧縮する（副作用）
    返り値: ソートされ重複要素を除いた値
    計算量: O(n log n)
*/
template <typename T>
vector<T> compress(vector<T> &C1, vector<T> &C2) {
    vector<T> vals;
    int N = (int)C1.size();
    int M = C2.size();
    for (int i = 0; i < N; i++) {
        for (T d = 0; d <= 1; d++) {  // その位置と、一つ隣を確保(隣を確保しないと空白が埋まってしまうことがある)
            T tc1 = C1[i] + d;
            vals.push_back(tc1);
        }
    }
    rep(i,M){
        for (T d = 0; d <= 1; d++) {  // その位置と、一つ隣を確保(隣を確保しないと空白が埋まってしまうことがある)
            T tc2 = C2[i] + d;
            vals.push_back(tc2);
        }
    }
    // ソート
    sort(vals.begin(), vals.end());
    // 隣り合う重複を削除(unique), 末端のゴミを削除(erase)
    vals.erase(unique(vals.begin(), vals.end()), vals.end());
    for (int i = 0; i < N; i++) {
        C1[i] = lower_bound(vals.begin(), vals.end(), C1[i]) - vals.begin();
    }
    rep(i,M){
        C2[i] = lower_bound(vals.begin(), vals.end(), C2[i]) - vals.begin();
    }
    return vals;
}
int main() {
    int N, M; // <= 2000
    cin >> N >> M;
    vector<int> px(N+M), py(N+M);
    vector<pair<int,int>> vp, vq;
    rep(i,N){
        cin >> px[i] >> py[i];
        vp.emplace_back(px[i],py[i]);
    }
    rep(i,M){
        cin >> px[N+i] >> py[N+i];
        vq.emplace_back(px[i+N], py[N+i]);
    }
    auto ps = compress(px, py);
    dump(px);
    dump(py);
    dump(ps);
    vector<pair<int, int>> xy, yx;
    rep(i,M){
        xy.emplace_back(px[N+i], py[N+i]);
        yx.emplace_back(py[N+i], px[N+i]);
    }
    sort(all(xy));
    sort(all(yx));
    vector<int> x_ymax(ps.back()+1, 0);
    vector<int> y_xmax(ps.back()+1, 0);
    for(int i = M-1; i >= 0; i--){
        x_ymax[xy[i].first] = xy[i].second;
        y_xmax[yx[i].first] = yx[i].second;
    }
    for(int i = x_ymax.size(); i >= 1; i--){
        chmax(x_ymax[i-1], x_ymax[i]);
        chmax(y_xmax[i-1], y_xmax[i]);
    }
    dump(x_ymax);
    dump(y_xmax);
    int maxx = ps.size();
    auto check2 = [&](int xidx, int yidx) -> bool{
        return x_ymax[ps[yidx]] < yidx && y_xmax[ps[xidx]] < xidx;
    };
    auto check = [&](ll X){
        bool res = false;
        // // x座標方向にi、y座標方向にjだけ動かす
        for(int i = 0; i <= X; i++){
            int j = X - i;
            auto x = px;
            auto y = py;
            rep(k,N){
                x[k] = min(maxx, x[k] + i);
                y[k] = min(maxx, y[k] + j);
            }
            // すべての監視のx座標に対して
            bool ok = true;
            rep(k,N){
                if(not check2(x[k], y[k]))ok = false;
            }
            if(ok)res = true;
        }
        return res;
    };
    ll ng = -1;
    ll ok = 10*(N+M);
    while(ok - ng > 1){
        ll mid = (ok + ng) >> 1;
        if(check(mid))ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
}
