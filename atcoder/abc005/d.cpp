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
class TwoDimCumsum {
public:
    int H,W;
    vector<vector<T>> d;
    TwoDimCumsum(T _H, T _W):H(_H),W(_W),d(_H+1,vector<T>(_W+1,0)){}

    void add(int x, int y, int a){
        d[x][y]+= a;
    }
    void build(){
        for(int i = 1; i <= H; ++i){
            for(int j = 1; j <= W; ++j){
                d[i][j] += d[i-1][j];
                d[i][j] += d[i][j-1];
                d[i][j] -= d[i-1][j-1];
            }
        }
    }
    //[sx, gx] & [sy, gy]
    T query(int sx, int sy, int gx, int gy){
        T res = d[gx][gy] - d[sx-1][gy] - d[gx][sy-1] + d[sx-1][sy-1];
        return res;
    }
    //confirm the 2d vector
    void debug(){
        for(int i = 0;i <= H;++i){
            for(int j = 0; j <= W; ++j){
                cerr<<d[i][j]<<((j == W) ? "\n":" ");
            }
        }
    }
};

/*
使い方
https://atcoder.jp/contests/abc106/submissions/9873594
1. インスタンス生成 縦横決める
TwoDimCumsum<int> Cumsum(H,W);
2. 座標に埋める
Cumsum.add(x, y, 1)
3. 二次元累積和計算
Cumsum.build()
4. 区間のクエリを受ける
Cumsumq.uery(p, q)
*/

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N;
    cin >> N;
    TwoDimCumsum<int> Cumsum(N,N);
    rep(i,N)rep(j,N){
        int d;
        cin >> d;
        Cumsum.add(i+1,j+1,d);
    }
    Cumsum.build();
    /*cal
    長方形全部列挙 N^4*/
    vec<l_l> v;
    //[lx,rx], [ly,ry]
    rep(lx,N)rep(rx,N)rep(ly,N)rep(ry,N){
        if(lx > rx)continue;
        if(ly > ry)continue;
        int menseki = (rx - lx+1) * (ry - ly+1);
        int sum = Cumsum.query(lx+1, ly+1, rx+1, ry+1);
        v.emplace_back(menseki, sum);
    }
    sort(all(v));
    vec<ll> prefix_max(v.size(),-1);
    prefix_max[0] = v[0].second;
    rep1(i,v.size()){
        chmax(prefix_max[i],prefix_max[i-1]);
        chmax(prefix_max[i],v[i].second);
    }
    int Q;
    cin >>  Q;
    while(Q--){
        int p;
        cin >> p;
        /*calc*/
        l_l upp = make_pair(p, INFLL);
        int idx = lower_bound(all(v), upp) - v.begin();
        idx--;
        ll ans = prefix_max[idx];
        cout << ans <<  endl;
    }
}