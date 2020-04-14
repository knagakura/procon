#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()		 //sort(all(vi S)) sort(all(string S))
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }

using P = pair<int, int>;		//P.first, P.second
typedef long long ll;
typedef vector<int> vi;
typedef set<int> seti;
typedef vector<string> vs;

const int MOD = 1e9+7;
const ll INF = 1e18 + 1;

void solve(){
    int N;
    cin>>N;
    vector<ll> a(N),b(N);
    rep(i,N){
        cin>>a[i]>>b[i];
    }
    
    ll dp[N][10];
    rep(i,N)rep(j,4){
        dp[i][j] = INF;
    }
    rep(i,4){
        dp[0][i] = i * b[0];
    }
    
    rep(i,N-1)rep(j,4)rep(k,4){
        if(a[i] + j == a[i+1] + k)continue;
        dp[i+1][k] = min(dp[i+1][k], dp[i][j] + k * b[i+1]);
    }
    ll ans = min({dp[N-1][0], dp[N-1][1], dp[N-1][2], dp[N-1][3]});
    cout<<ans<<endl;
    return;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int q;
    cin>>q;
    rep(i,q){
        solve();
    }
}