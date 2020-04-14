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
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;

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
        return d[gx][gy] - d[sx-1][gy] - d[gx][sy-1] + d[sx-1][sy-1];
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
Cumsum.query(p, q)
*/

int H, W, K;
vector<string> S;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    cin >> H >> W >> K;
    S.resize(H);
    rep(i,H)cin >> S[i];

    TwoDimCumsum<int> Cumsum(H,W);
    rep(i,H)rep(j,W){
        Cumsum.add(i+1, j+1, S[i][j] - '0');
    }
    
    Cumsum.build();
    Cumsum.debug();
    /*
    vvec<int> cum(H+1, vec<int>(W,0));
    rep(j,W){
        rep(i,H){
            cum[i+1][j] += cum[i][j] + S[i][j] - '0';
        }
    }*/
    //rep(i,H+1)print(cum[i]);
    ll ans = INFLL;
    //境界の状態を全探索
    rep(k,bit(H-1)){
    //rep(k,1){                    // 2^9
        // l個目の境界が分かれているか
        vector<int> v;
        v.push_back(0); 
        ll cnt = 0; // 境界の本数
        rep(l, H-1){                    
            if(k & bit(l)){
                v.push_back(l+1);
                cnt++;
            }
        }
        v.push_back(H);
        //print(v);
        //区間が決まっているので、右端を二分探索
        int start = 0;
        int l = 0;int r = W;
        vector<int> counts(int(v.size()-1),0);
        auto check = [&](int x){
            int maxx = 0;
            //横[start, mid]
            rep(m, v.size()-1){
                int ue = v[m];
                int sita  = v[m+1];
                cerr << ue << " " <<sita << endl;
                cerr << start << " "<< x << endl << Cumsum.query(ue+1, start+1, sita, x+1)<<endl;
                
                chmax(maxx, Cumsum.query(ue+1, start, sita+1, x));
            }
            return maxx <= K;
        };
        while(true){
            l = start;
            r = W;
            while(r - l > 1){
                int mid = (l + r) / 2;
                if(check(mid))l = mid;
                else r = mid;
            }
            start = r;
            if(r == W)break;
            cnt++;
        }
        /*
        rep(j,W){                           // 1000
            vector<int> nxt((int)v.size()-1, 0);
            int maxx = 0; //区間の中のmax
            rep(m, v.size()-1){             // 10 m番目の区間
                int l = v[m];
                int r = v[m+1];
                //cerr << l << " "  <<  r <<endl;
                //[l,r)行ごとに分ける
                nxt[m] = counts[m];
                //j行目の、[l,r)の足し算
                
                //for(int i = l;i < r;i++){
                //   nxt[m] += S[i][j] - '0';
                //}
                nxt[m] +=  cum[r][j] - cum[l][j];
                chmax(maxx, nxt[m]);
            }
            //print(nxt);
            if(maxx <= K){
                swap(counts,nxt);
            }
            else{
                j--;
                counts.assign((int)v.size()-1,0);
                cnt++;
                continue;
            }
        }
        */

        print(v);

        cerr << cnt << endl;

       
        chmin(ans, cnt);
    }
    cout << ans << endl;
}