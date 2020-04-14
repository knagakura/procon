#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }

typedef long long ll;

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = 1e9;
const ll INFLL = 1e18;
const ll MOD = 1e9+7;

const double PI = acos(-1.0);

int main() {


    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N,T;
    cin>>N>>T;
    vector<pair<int,int>> vp;
    rep(i,N){
        int a,b;
        cin>>a>>b;
        vp.push_back({a,b});
    }
    sort(all(vp));
    vector<int> A(N),B(N);
    rep(i,N){
        A[i] = vp[i].first;
        B[i] = vp[i].second;
    }
    vector<vector<ll>> dp(N+1,vector<ll>(T+1,0));
    rep(i,N){
        rep(t,T){
            chmax(dp[i+1][t], dp[i][t]);
            chmax(dp[i + 1][T], dp[i][T]);
            chmax(dp[i+1][min(t + A[i],T)], dp[i][t] + B[i]);
        }
    }
    ll ans = 0;
    rep(t,T+1){
        chmax(ans, dp[N][t]);
    }
    cout<<ans<<endl;
}