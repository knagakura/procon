#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
// #define bit(k) (1LL<<(k))
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
#include <atcoder/string>
using namespace atcoder;

template< typename T >
struct BIT {
  vector< T > data;
 
  BIT(int sz) {
    data.assign(++sz, 0);
  }
 
  // 閉区間 [0, k] の和を求める
  // k は（指定したsz）-1　までしか値を取れない
  T sum(int k) {
    T ret = 0;
    for(++k; k > 0; k -= k & -k) ret += data[k];
    return (ret);
  }
 
  // 閉区間 [k, l] の和を求める
  T segment_sum(int k, int l){
      T ret = 0;
      ret += sum(l);
      ret -= sum(k-1);
      return (ret);
  }
 
  // 要素 k に x を加える
  void add(int k, T x) {
    for(++k; k < (int)data.size(); k += k & -k) data[k] += x;
  }
 
  // 要素 k を x の変更
  void update(int k, T x){
      T tmp = segment_sum(k, k);
      add(k, x-tmp);
  }
 
  // 二分探索 [0, k]　の和が w 以上になるような最小の k を求める
  // 値が全て0以上じゃないと無理
  // 存在しなければ sz-1 を返す
  // w<=0 のときは -1 を返す
  int lower_bound(T w){
      if(w<=0) return -1;
 
      int sz = data.size();
      int x = 0, r = 1;
      while(r < sz-1) r = (r << 1);
      for(int len = r; len > 0; len = (len >> 1)){
          if(x + len <= sz-1 and data[x + len] < w){
              w -= data[x + len];
              x += len;
          }
      }
      return x;
  }
 
  // 全ての要素をprint
  void print(){
      cout << "Line" <<  __LINE__  << ": BIT = ";
      for(int i=0;i<(int)data.size()-1;i++) cout << segment_sum(i, i) << " ";
      cout << "\n";
  }
};
template<class T>
ll inversion_count_between(vector<T> &x, vector<T> &y){
    // x を y にするために必要な最小 swap 回数（転倒数）を計算
    // 同じ値が含まれても良い（最小のswap回数になる）
    // 座標圧縮も勝手にやってくれる
    // x を y にできない場合 -1 を返す
    // ちょっと遅い
 
    int sz = x.size();
 
    assert(sz = (int)y.size());
 
    BIT<ll> bit(sz);
 
    map<T, vector<int>> loc;
    for(int i=sz-1;i>=0;i--){
        loc[x[i]].push_back(i);
    }
 
    ll res = 0;
    for(int i=0;i<sz;i++){
        vector<int> &v = loc[y[i]];
        if(v.empty()) return -1;
        int id = v.back(); v.pop_back();
        res += id - bit.sum(id-1);
        bit.add(id, 1);
    }
 
    return res;
}

const string T = "atcoder";
 
int solve(string S){
    int N = S.size();
    // 最初からOK
    if(T < S){
        return 0;
    }
    // サイズが同じかそれ以下
    if(S.size() <= T.size()){
        vector<int> v(N), w(N);
        rep(i,N)v[i] = S[i] - 'a';
        sort(all(S));
        int ans = INF;
        sort(all(S));
        do{
            rep(i,N)w[i] = S[i] - 'a';
            if(T >= S)continue;
            int tmp = inversion_count_between(v, w);
            if(chmin(ans, tmp)){
            }
        }while(next_permutation(all(S)));
        return ans == INF ? -1: ans;
    }
    // サイズが大きくて、最初からは無理
    int ans = I
    vector<bool> used(N, false);
    rep(i,T.size()){
        bool ok = false;
        rep(j,N){
            if(not used[j] && T[i] < S[j]){
                used[j] = true;
                ans += j - i;;
            }
        }
    }
    return ans == INF ? -1: ans;
}
int solve2(string S){
    int ans = INF;
    int N = S.size();
    vector<int> v(N);
    rep(i,N)v[i] = S[i] - 'a';
    sort(all(S));
    sort(all(S));
    do{
        vector<int> w(N);
        rep(i,N)w[i] = S[i] - 'a';
        int tmp = inversion_count_between(v, w);
        if(T < S){
            chmin(ans, tmp);
        }
    }while(next_permutation(all(S)));
    return ans == INF ? -1:  ans;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        string S;
        cin >> S;
        int ans1 = solve(S);
        // int ans2 = solve2(S);
        cout << ans1 << endl;
        // if(ans1 != ans2){
        //     dump(S);
        //     dump(ans1, ans2);
        // }
        // else{
        //     dump("OK");
        //     dump(ans1, ans2);
        // }
    }
}
