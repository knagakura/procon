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
    ll dp[100][2][2] = {};
    dp[0][0][0] = 1;
    for(int i = 0; i < N; i++)rep(j,2)rep(k,2){
        int num = S[i]-'0';
        for(int d = 0; d <= (j ? 9:num);d++){
            dp[i+1][j || (d < num)][k || d == 4 || d == 9] += dp[i][j][k];
        }
    }
    return dp[N][1][1] + dp[N][0][1];
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