#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define dump(x) cerr<<#x<<": "<<x<<endl;
#define bit(k) (1LL<<(k))
typedef long long ll;
typedef pair<int, int> i_i;
typedef pair<ll, ll> l_l;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;
template< typename T1, typename T2 >
ostream &operator<<(ostream &os, const pair< T1, T2 >& p) {
  os << "{" <<p.first << ", " << p.second << "}";
  return os;
}
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = (ll)1e9;
const ll INFLL = (ll)1e18+1;
const ll MOD = (ll)1e9+7;
const double PI = acos(-1.0);
/*
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const string dir = "DRUL";
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
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N, K;
    cin >> N >> K;
    vector<ll> A(N);
    vector<l_l> v;
    rep(i, N){
        cin >> A[i];
        v.push_back({A[i], i});
    }
    sort(all(v));
    if(K == N){

    }
    ll ng = -1;
    ll ok = N;
    auto check = [&](ll idx) -> bool{
        //最小値v[idx].firstの長さlenの区間（1個以上離れている）を取ることができるか
        int len[] = {K - K/2, K/2};
        rep(j,2){
            vector<l_l> tmp;
            vector<bool> ng(N, false);
            //j == 0: 最初の一個含めるやつ
            if(j == 0){
                tmp.push_back(v[0]);
                ng[v[0].second] = true;
                for(int i = 1; i < N; i++){
                    if(v[i].second + 1 <  N && ng[v[i].second + 1])continue;
                    if(v[i].second - 1 >= 0 && ng[v[i].second - 1])continue;
                    tmp.push_back(v[i]);
                    if(tmp.size() >= len[j])break;
                }
            }
            //j == 1: 最初の一個含めないやつ
            else{
                tmp.push_back(v[1]);
                for(int i = 2; i < N; i++){
                    if(v[i].second + 1 < N && ng[v[i].second + 1])continue;
                    if(v[i].second - 1 < 0)continue;
                    if(tmp.size() >= len[j])break;
                }
            }
        }
        return false;
    };
    while(ok - ng > 1){
        ll mid = (ok + ng) / 2;
        if(check(mid))ok = mid;
        else ng = mid;
    }
    cout << v[ok].first << endl;
}