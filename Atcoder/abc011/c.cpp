#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }

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
    int N;
    cin>>N;
    vector<bool> NG(301,false);
    rep(i,3){
        int ng;cin>>ng;
        NG[ng] = true;
    }
    int dp[305][105];
    rep(i,101)dp[N][i] = 1;
    for(int i = N; i >=0; i--){
        for(int cnt = 0; cnt <= 100; cnt++){
            if(NG[i])continue;
            if(dp[i][cnt] == 0)continue;
            dp[i][cnt+1] = 1;
            if(i-1 >= 0)dp[i-1][cnt+1] = (NG[i-1] ? 0:1);
            if(i-2 >= 0)dp[i-2][cnt+1] = (NG[i-2] ? 0:1);
            if(i-3 >= 0)dp[i-3][cnt+1] = (NG[i-3] ? 0:1);
        }
    }
    cout<<(dp[0][100]==1 ? "YES":"No")<<endl;
}