#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define dump(x) cerr<<#x<<": "<<x<<endl;
typedef long long ll;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
ll dp[3333][3333];

int main() {
    ll N, T;
    cin >> N >> T;
    vector<pair<ll,ll>> ab;
    rep(i,N){
        ll a, b;
        cin >> a >> b;
        ab.push_back({a,b});
    }
    //sort(all(ab));
    rep(i,N+5)rep(j,T+5)dp[i][j] = 0;
    rep(i,N)rep(j,T){
        ll w = ab[i].first;
        ll v = ab[i].second;
        chmax(dp[i+1][j], dp[i][j]);
        if(j + w >= T)continue;
        chmax(dp[i+1][j+w], dp[i][j] + v);
    }
    printpair(ab);
    ll ans = 0;
    rep(i,N)rep(j,T){
        if(chmax(ans, dp[i][j] + ab[i].second)){
            cerr << i << " " << j << endl;
            dump(ans);
        };
    }
    cout << ans <<endl;
}