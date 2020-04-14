//http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1167&lang=jp
//https://onlinejudge.u-aizu.ac.jp/problems/1167
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
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    vector<ll> dp(1000005,INF);
    vector<ll> dp2(1000005,INF);
    dp[0] = dp2[0] = 0;
    for(int i = 1; i <=1000000;i++){
        for(int j = 1;;j++){
            int num = (j * (j + 1) * (j + 2))/6;
            if(i-num < 0)break;
            chmin(dp[i],dp[i-num] + 1);
            if(num % 2 == 1){
                chmin(dp2[i],dp2[i-num] + 1);
            }
        }
    }
    while(1){
        int N;
        cin>>N;
        if(N == 0)break;
        cout<<dp[N]<<" "<<dp2[N]<<endl;
    }
    return 0;
}
