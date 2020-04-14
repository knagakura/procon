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

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = (ll)1e9;
const ll INFLL = (ll)1e17;
const ll MOD = (ll)1e9+7;
const double PI = acos(-1.0);
/*
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const string dir = "DRUL";
*/
template<typename T>
vector<T> cumulative_sum(vector<T> &v) {
    vector<T> sum(v.size() + 1);
    for(int i = 0; i < (int)v.size(); ++i){
        sum[i+1] = sum[i] + v[i];
    }
    return sum;
}
/*使うとき
vector<int> a(N);
auto cum = cumlative_sum(a)
とするとvector<int> cumが生成される

i番目までの仕切りの和
cum[i]: [0,i)の和（半開区間）

要素i~jの和が欲しい時
j+1 ~ i番目の仕切りまで数えればよい
int sum = cum[j+1]-cum[i]
*/
int N;
//dp[l][r]: [l, r)の区間を作るための最小値
ll dp[432][432];
void debug(){
    rep(i,N){
        rep(j,N){
            if(dp[i][j] == INFLL)cerr<<-1<<" ";
            else cerr<<dp[i][j]<<" ";
        }
        cerr<<endl;
    }
    cerr<<endl;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    cin >> N;
    vector<ll> a(N);
    rep(i,N)cin>>a[i];
    auto cum = cumulative_sum(a);
    auto summ = [&](int l, int r){
        return cum[r] - cum[l];
    };

    rep(i, N+1)rep(j, N+1){
        dp[i][j] = INFLL;
    }
    //長さ0, 1の場合の初期化
    rep(i,N+1){
        dp[i][i] = 0;
        dp[i][i+1] = 0;
    }
    //長さを全探索
    for(int len = 2; len <= N; len++){
        for(int l = 0; l < N; l++){
            int r = l + len;
            if(r > N)continue;
            for(int k = l;k <= r;k++){
                chmin(dp[l][r], dp[l][k] + dp[k][r] + summ(l,r));            
            }
        }
    }
    cout << dp[0][N] << endl;
}