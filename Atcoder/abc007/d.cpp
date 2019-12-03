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

ll count(ll X){
    string S = to_string(X);
    int N = S.size();
    ll dp[100][2] = {};
    dp[0][0] = 1;
    rep(i,N+1)rep(j,2){
        cerr<<dp[i][j];
        if(j == 1)cerr<<endl;
        else cerr<<" ";
    }
    for(int i = 0; i < N; i++){
        int num = S[i]-'0';//上からi桁目
        cerr<<i<<"桁目"<<num<<endl;
        rep(j,10){
            if(j == 4||j == 9)continue;
            if(j < num){//確定に遷移
                dp[i+1][1] += dp[i][0];
                dp[i+1][1] += dp[i][1];
            }
            else{
                dp[i+1][0] += dp[i][0];
            }
        }
    }
    rep(i,N+1)rep(j,2){
        cerr<<dp[i][j];
        if(j == 1)cerr<<endl;
        else cerr<<" ";
    }
    return X - (dp[N][0] + dp[N][1]);
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    ll A,B;
    cin>>A>>B;

    //  0~B       の中にある禁止された数
    //- 0~A-1   の中にある禁止された数

    ll ans = count(B) - count(A-1);
    cout<<ans<<endl;
}