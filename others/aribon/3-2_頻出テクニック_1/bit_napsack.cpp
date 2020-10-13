#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define bit(k) (1LL<<(k))
typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = 1e9;
const ll INFLL = 1e18;
const ll MOD = 1e9+7;
const double PI = acos(-1.0);

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

/*------------------------------------/
for library*/

/*------------------------------------*/
int N;
ll W;
vector<ll> v,w;
ll maxW, maxV;
//solve1
vector<pair<ll,ll>> ps;

//solve2,3
ll dp[216][202020];

//入力
void input(){
    cin >> N >> W;
    v.resize(N); w.resize(N);
    maxW = maxV = 0;
    rep(i,N){
        cin>>v[i]>>w[i];
        chmax(maxW, w[i]);
        chmax(maxV, v[i]);
    }
}
//Nが小さい -> 半分全列挙
void solve1(){
    //片方を全列挙
    int n2 = N/2;
    //半分の選ぶ選ばないを全列挙
    for(int i = 0; i < bit(n2);i++){
        ll sw = 0;
        ll sv = 0;
        for(int j = 0;j < n2;j++){
            if(i & bit(j)){
                sw += w[j];
                sv += v[j];
            }
        }
        ps.push_back({sw, sv});
    }
    sort(all(ps));
    //不要なものを除く（wが大きいのに価値が小さいものを除く）
    ll m = 1;
    for(int i = 1; i < bit(n2);i++){
        if(ps[m-1].second < ps[i].second){
            ps[m] = ps[i];
            m++;
        }
    }

    ll ans = 0;
    //後ろ半分を列挙して解を求める
    for(int i = 0; i < bit(N - n2);i++){
        ll sw = 0;
        ll sv = 0;
        for(int j = 0; j < N-n2; j++){
            if(i & bit(j)){
                sw += w[j + n2];
                sv += v[j + n2];
            }
        }
        if(sw <= W){
            ll idx = lower_bound(all(ps),make_pair(W - sw,INFLL)) - ps.begin();
            ll tv = ps[idx-1].second;
            chmax(ans, sv + tv);
        }
    }
    cout << ans <<endl;
}

//wが小さいdp
//dp[i][w]
//i番目までの商品で、重さw以下で実現できる最大の価値v
void solve2(){
    rep(i,210)rep(j,202000){
        dp[i][j] = 0;
    }
    dp[0][0] = 0;
    rep(i,N)rep(j,202000){
        chmax(dp[i+1][j],dp[i][j]);
        if(j + w[i] <= 202000){
            chmax(dp[i+1][j+w[i]], dp[i][j] + v[i]);
        }
    }
    cout << dp[N][W] << endl;
}

//vが小さいdp
//dp[i][v]
//i番目までの商品で、価値vを実現するのに必要な最小のw
void solve3(){
    rep(i,210)rep(j,202000){
        dp[i][j] = INFLL;
    }
    dp[0][0] = 0;
    rep(i,N)rep(j,202000){
        chmin(dp[i+1][j], dp[i][j]);
        if(j + v[i] <= 202000){
            chmin(dp[i+1][j + v[i]], dp[i][j] + w[i]);
        }
    }
    ll ans = 0;
    rep(j, 202000){
        if(dp[N][j] <= W){
            chmax(ans, (ll)j);
        }
    }
    cout<<ans<<endl;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    input();
    
    if(N <= 30){
        solve1();
    }
    else if(maxW <= 1000){
        solve2();
    }
    else{
        solve3();
    }
}