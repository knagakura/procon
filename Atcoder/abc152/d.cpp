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
//桁数、先頭の数、末尾の数
ll dp[10][10][10];
//桁数がNと一致した場合に注意が必要

//桁数が一致する場合を数え上げる
//桁数はmaxのみのものを数えるので、0入れない
ll dp2[10][10][10][2];
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N;
    cin>>N;
    int keta = to_string(N).size();
    if(keta == 1){
        cout<<N<<endl;
        return 0;
    }
    //keta >= 2
    ll ans = 0;
    rep1(i,keta+1)rep1(j,10)rep1(k,10){
        //最後の桁のときは、bitDPの考え方を使う？N以下の数の列挙
        if(i == keta){
            rep1(top,10){
                if(top == N/(int)pow(10,keta-1)){

                }
            }
        }
        else{
            dp[i][j][k] = pow(10,keta-2);
        }
    }

    //a桁とb桁の組み合わせ全て
    rep1(a,keta+1)rep(b,keta+1){
        rep1(j,10)rep1(k,10){
            ans += dp[a][j][k] * dp[b][k][j];
        }
    }
    cout<<ans<<endl;
}