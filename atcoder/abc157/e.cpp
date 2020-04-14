#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()

#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<std::bitset<26>(_)<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define dump(x) cerr<<#x<<": "<<x<<endl;

#define bit(k) (1LL<<(k))

typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = (ll)1e9;
const ll INFLL = (ll)1e18;
const ll MOD = (ll)1e9+7;
const double PI = acos(-1.0);

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

/*------------------------------------/
for library*/
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
        return data[i + N-1];
    }
    void set(int i, T x){
        data[i + N] = x;
    }
    void build(){
        for(int i = N-1; i >= 0; i--){
            data[i] = op(data[2 * i], data[2 * i + 1]);
        }
    }
    void debug(){
        cerr<<"data: [";
        for(auto x:data){
            cerr<<"( ";
            rep(i,26){
                if(x & bit(i)){
                    cerr<<char(i + 'a')<<", ";
                }
            }
            cerr<<"), ";
        }
        cerr<<"]"<<endl;
    }
};


/*------------------------------------*/

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    string S;
    int Q;
    cin>>N>>S>>Q;
    SegTree<ll> seg(N, 0,
                    [](int a, int b){return a | b;},
                    [](int a, int b){return bit(b);});
    for(int i = 0; i < N; i++){
        cerr<<bit(S[i]-'a')<<endl;
        seg.set(i, bit(S[i] - 'a'));
    }
    seg.build();
    while(Q--){
        int x;
        cin>>x;
        if(x == 1){
            int i;char c;
            cin>>i>>c;
            i--;
            seg.change(i, c - 'a');
        }
        else{
            int l, r;
            cin>>l>>r;
            l--;r--;
            cout<<__builtin_popcountll(seg.query(l,r+1))<<endl;
        }
        seg.debug();
    }
}