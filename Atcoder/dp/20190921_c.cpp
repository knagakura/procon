#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }

using P = pair<int, int>;
typedef long long ll;

const int MOD = 1e9+7;
const int INF = 1e9;
ll dp[123456][3] = {};
ll a[123456][3];
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin>>N;
    rep(i,N)cin>>a[i][0]>>a[i][1]>>a[i][2];
    rep(i,3){
        dp[0][i] = a[0][i];
    }
    rep(i,N)rep(pre, 3)rep(pos, 3){
        if(pre == pos)continue;
        dp[i+1][pos] = max(dp[i+1][pos], dp[i][pre] + a[i+1][pos]);
    }
    cout<<max({dp[N][0],dp[N][1],dp[N][1]})<<endl;
}