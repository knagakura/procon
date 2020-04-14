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
int table[1001][1001] = {};
int H,W;
vector<int> r,c;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>H>>W;
    r.resize(H);c.resize(W);
    rep(i,H)cin>>r[i];
    rep(i,W)cin>>c[i];
    rep(i,H)rep(j,W){
        table[i][j] = INF;
    }
    rep(i,H)rep(j,r[i]+1){
        if(j<r[i])table[i][j] = 1;
        else if(j == r[i])table[i][j] =0;
    }
    rep(j,W)rep(i,c[j]+1){
        if(i<c[j]){
            if(table[i][j]==INF){
                table[i][j] = 1;
            }
            else if(table[i][j] == 0){
                cout<<0<<endl;
                return 0;
            }
        }
        else if(i == c[j]){
            if(table[i][j] == INF){
                table[i][j] = 0;
            }
            else if(table[i][j] == 1){
                cout<<0<<endl;
                return 0;
            }
        }
    }
    ll ans = 1;
    rep(i,H)rep(j,W){
        if(table[i][j] == INF){
            ans *= 2;
            ans %= MOD;
        }
    }
    /*
    rep(i,H)rep(j,W){
        cout<<table[i][j];
        if(j == W-1)cout<<endl;
        else cout<<" ";
    }
    */
    cout<<ans<<endl;
}