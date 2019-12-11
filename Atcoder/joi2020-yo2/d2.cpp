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
ll modpow(ll a, ll n, int mod) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % mod;
        a = a * a % mod;
        n >>= 1;
    }
    return res;
}
/*------------------------------------*/
ll dp[20][100005][11];
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    //前処理
    //多点間最短距離を求める
    int dist[10][10];
    rep(i,10)rep(j,10)dist[i][j] = INF;
    rep(i,10)rep(j,10){
        if(j < i)continue;
        if(i == j)dist[i][j] = 0;
        if(i == 0&&j == 1){
            dist[i][j] = dist[j][i] = 1;
        }
        if(j-i == 3&&i != 0){
            dist[i][j] = dist[j][i] = 1;
        }
        if(j-i ==1 && i%3!=0){
            dist[i][j]  = dist[j][i]  = 1;
        }
    }
    
    rep(k,10)rep(i,10)rep(j,10){
        dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
    }
    //
    ll M,R;
    cin>>M>>R;
    rep(i,15)rep(j,M+5)rep(k,10){
        dp[i][j][k] = INF;
    }
    dp[0][0][0] = 0;
    //10^{i}の桁を決める
    for(int i = 0; i < 12;i++){
        //Mで割った余りがjのところからスタート
        for(int j = 0;j < M;j++){
            //遷移元の数字を決める
            rep(k,10){
                //遷移先はl
                rep(l,10){
                    ll nextmod = (modpow(10,i,M) * l + j) % M;
                    //次の桁の数字を決める
                    chmin(dp[i+1][nextmod][l],dp[i][j][k] + dist[k][l]+1);
                }
            }
        }
    }
    ll ans = INFLL;
    rep(i,15)rep1(k,10){
        chmin(ans, dp[i][R][k]);
    }
    cout<<ans<<endl;
}