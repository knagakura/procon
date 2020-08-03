#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define dump(x) cerr<<#x<<": "<<x<<endl;
#define bit(k) (1LL<<(k))
#define Yes "Yes"
#define No "No"
#define YES "YES"
#define NO "NO"
typedef long long ll;

template< typename T1, typename T2 >
ostream &operator<<(ostream &os, const pair< T1, T2 >& p) {
  os << "{" <<p.first << ", " << p.second << "}";
  return os;
}
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = (ll)1e9;
const ll INFLL = (ll)1e18+1;
const ll MOD = (ll)1e9+7;

const double PI = acos(-1.0);

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const string dir = "DRUL";



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

int main(){
    int N;
    cin >> N;    
    long long inf = (1LL << 31) - 1;
    auto f = [&](long long a, long long b){
        return min(a, b);
    };
    auto g = [&](long long a, long long b){
        return b;
    };
    SegTree<long long> Tree(N,inf,f,g);
    vector<ll> A(N);
    rep(i, N)cin >> A[i];
    rep(i,N)Tree.change(i, A[i]);
    auto checkl = [&](int l, int r) -> bool{
        return Tree.query(l,r) == A[r-1];
    };
    auto checkr = [&](int l, int r) -> bool{
        return Tree.query(l,r) == A[l];
    };
    ll ans = 0;
    rep(i,N){
        // calc 左端と右端を計算する O(logN)
        ll l, r;
        {
            int ng = -1;
            int ok = i;
            while(ok - ng > 1){
                int mid = (ok + ng) >> 1;
                if(checkl(mid, i+1))ok = mid;
                else ng = mid;
            }
            l = i+1 - ok;
        }
        {
            int ok = i+1;
            int ng = N+1;
            while(ng - ok > 1){
                int mid = (ok + ng) >> 1;
                if(checkr(i,mid))ok = mid;
                else ng = mid;
            }
            r = ok - i;
        }
        ll cnt = l * r;
        ans += cnt * A[i];
    }
    cout << ans << endl;
}
