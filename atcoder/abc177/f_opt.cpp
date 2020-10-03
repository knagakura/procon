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
#include <atcoder/lazysegtree>
struct S { int min, l; };

using F = int;

S op(S sl, S sr) { return {min(sl.min, sr.min), min(sl.l, sr.l)}; }

S e() { return {INF, INF}; }

S mapping(F f, S s) {
  if (f == INF) return s;
  return {s.l + f, s.l};
}

F composition(F f, F g) {
  if (f == INF) return g;
  return f;
}

F id() { return INF; }


int main() {
  int h, w; cin >> h >> w;

  vector<S> v(w);
  rep(i, w) v[i] = {0, i};
  atcoder::lazy_segtree<S, op, e, F, mapping, composition, id> seg(v);
  auto outs = [&](int idx){
      dump(idx);
      rep(i,w){
          int val = seg.get(i).min;
          cerr << (val >= w ? "-": to_string(val)) << " ";
      }
      cerr << endl;
  };
  outs(0);
  rep(i, h) {
    int a, b; cin >> a >> b;
    --a;
    dump(a, b);
    int x = 1e5;
    if (a > 0) x = seg.prod(a-1, a).min;
    dbg("apply: [", a, b, ")", x-a+1);
    seg.apply(a, b, x-a+1);
    int dist = seg.all_prod().min;
    int ans = -1;
    if (dist < w) ans = dist + i + 1;
    outs(i+1);
    cout << ans << '\n';
  }
}
