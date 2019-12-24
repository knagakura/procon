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
int n;
ll dp[212345][2];
void debug(){
    rep(i,n){
        cerr<<dp[i][0]<<" ";
    }
    cerr<<endl;
    rep(i,n ){
        cerr<<dp[i][1]<<" ";
    }
    cerr<<endl;
}
void solve(){
    cin>>n;
    vector<pair<int,int>> v;
    rep(i,n+5){
        dp[i][0] = dp[i][1] = INF;
    }
    dp[0][0] = 0;
    dp[0][1] = 1;
    rep(i,n){
        string s;
        cin>>s;
        int l = s[0]-'0';
        int r = s[s.size()-1]-'0';
        v.push_back({l,r});
    }
    //printpair(v);

    rep(i,n-1){
        int l0 = v[i].first;
        int r0 = v[i].second;
        int l1 = v[i+1].first;
        int r1 = v[i+1].second;
        //そのまま
        if(r0 == l1){
            chmin(dp[i+1][0],dp[i][0]);
        }
        //手前を反転
        if(l0 == l1){
            chmin(dp[i+1][0],dp[i][1]);
        }
        //次を反転
        if(r0 == r1){
            chmin(dp[i+1][1],dp[i][0]+1);
        }
        //両方反転
        if(l0 == r1){
            chmin(dp[i+1][1],dp[i][1]+1);
        }
    }
    //debug();
    ll ans = min(dp[n-1][0],dp[n-1][1]);
    if(ans == INF){
        cout<<-1<<endl;
        return;
    }
    cout<<ans<<endl;
    if(ans == 0){
        cout<<endl;
        return;
    }
    vector<int> w;
    int pre = 0;
    if(ans == dp[n-1][1]){
        w.push_back(n);
        pre = 1;
    }
    for(int i = n-1;i >=1;i--){
        if(pre == 0){
            if(dp[i-1][0] == dp[i][pre]){
                pre = 0;
                continue;
            }
            else{
                pre = 1;
                w.push_back(i);
                continue;
            }
        }
        //1へ遷移
        else{
            if(dp[i-1][0] + 1 == dp[i][pre]){
                pre = 0;
                continue;
            }
            else{
                pre = 1;
                w.push_back(i);
                continue;
            }
        }
    }
    //print(w);
    reverse(all(w));
    rep(i,ans){
        cout<<w[i];
        if(i == ans-1)cout<<endl;
        else cout<<" ";
    }
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int t;
    cin>>t;
    while(t--){
        solve();
    }
}