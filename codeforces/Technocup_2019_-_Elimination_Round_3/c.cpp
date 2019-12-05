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
int dp[234567][10] = {};
void debug(){
    rep1(j,6)rep(i,N){
        cerr<<dp[i][j];
        if(i == N-1)cerr<<endl;
        else cerr<<" ";
    }
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    cin>>N;
    vector<ll> a(N);
    rep(i,N)cin>>a[i];
    int r1;
    rep(l1,N-1){
        if(a[l1] < a[l1+1]){
            r1 = l1+1;
            while(r1 < N && a[r1] < a[r1+1]){
                r1++;
            }
            cerr<<l1<<" "<<r1<<endl;
            int len = r1-l1;
            //dpの更新
            rep1(j,5-len+1){
                dp[l1][j] = 1;
            }
            for(int i = l1;i < r1;i++){
                rep1(j,6){
                    dp[i+1][j+1] += dp[i][j];
                }
            }
            l1 = r1;
        }
    }

    debug();
    int l2;
    for(int r2 = N-1;r2 >=1;r2--){
        if(a[r2-1] > a[r2]){
            l2= r2-1;
            while(0 <= l2&&a[l2-1]>a[l2]){
                l2--;
            }
            cerr<<l2<<" "<<r2<<endl;
            int len = r2-l2;
            for(int j = 5;j > len;j--){
                dp[l2][j] = 1;
            }
            for(int i = l2;i < r2;i++){
                rep1(j,6){
                    dp[i+1][j-1]+=dp[i][j];
                }
            }
            r2 = l2;
        }
    }
    debug();
}