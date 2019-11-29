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

ll H,W,K,V;
ll A[130][130];
ll cnt[130][130];
/*------------------------------------/
for library*/
void debug(){
    rep(i,H){
        rep(j,W){
            cerr<<A[i][j]<<" ";
        }
        cerr<<endl;
    }
    cerr<<endl;

    rep(i,H+1){
        rep(j,W+1){
            cerr<<cnt[i][j]<<" ";
        }
        cerr<<endl;
    }
    cerr<<endl;
}
/*------------------------------------*/

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    cin>>H>>W>>K>>V;
    rep(i,H)rep(j,W){
        cin>>A[i][j];
    }
    rep(i,H)rep(j,W){
        cnt[i+1][j+1] = cnt[i+1][j] + cnt[i][j+1] - cnt[i][j]+ A[i][j];
    }
    //debug();
    ll ans = 0;
    rep(x1,H)rep(y1,W){
        for(int x2 = x1; x2 <=H;x2++){
            for(int y2 = y1; y2 <= W;y2++){
                ll okane = cnt[x2][y2] - cnt[x2][y1] - cnt[x1][y2] + cnt[x1][y1];
                ll S = (x2 - x1) * (y2 - y1);
                okane += S * K;
                if(okane <= V){
                    chmax(ans,S);
                }
            }
        }
    }
    cout<<ans<<endl;
}