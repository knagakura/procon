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
const ll INFLL = 1e9;
const ll MOD = 1e9+7;
const double PI = acos(-1.0);

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

/*------------------------------------/
for library*/

/*------------------------------------*/
ll dpr[55][110];
ll dpl[55][110];
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N,K;
    cin>>N>>K;
    vector<ll> V(N);
    rep(i,N)cin>>V[i];
    rep(i,55)rep(j,110){
        dpr[i][j] = -INFLL;
        dpl[i][j] = -INFLL;
    }
    dpl[0][0] = 0;
    rep(i,N)rep(j,K){
        //chmax(dpl[i+1][j], dpl[i][j]);
        if(dpl[i][j] == -INFLL)continue;
        //一回取って、価値を上げる
        if(V[i] >= 0){
            chmax(dpl[i+1][j+1], dpl[i][j] + V[i]);
        }
        //一回取って価値を下げるか、
        //取って捨てて価値を+-0にするか
        else{
            chmax(dpl[i+1][j+1], dpl[i][j] + V[i]);
            chmax(dpl[i+1][j+2], dpl[i][j]);
        }
    }
    dpr[N][0] = 0;
    for(int i = N-1;i >= 0;--i){
        rep(j,K){
            //chmax(dpr[i+1][j],dpr[i][j]);
            if(dpr[i+1][j] == -INFLL)continue;
            if(V[i] >=0){
                chmax(dpr[i][j+1],dpr[i+1][j] + V[i]);
            }
            else{
                chmax(dpr[i][j+1], dpr[i+1][j] + V[i]);
                chmax(dpr[i][j+2], dpr[i+1][j]);
            }
        }
    }
    rep(k,K+1)rep(i,N){
        chmax(dpl[i+1][k], dpl[i][k]);
        chmax(dpr[i+1][k], dpr[i][k]);
    }
    rep(k,K+1){
        chmax(dpl[N][k+1],dpl[N][k]);
        chmax(dpr[N][k+1],dpr[N][k]);
    }
    ll ans = 0;
    rep(t,K+1){
        chmax(ans, dpl[N][t] + dpr[N][K-t]);
    }
    cout<<ans<<endl;
    /*
    rep(i,N+1)rep(k,K+1){
        if(dpl[i][k] == -INFLL){
            cerr<<".";
        }
        else cerr<<dpl[i][k];
        if(k == K)cerr<<endl;
        else cerr<<" ";
    }

    cerr<<endl;
    rep(i,N+1)rep(k,K+1){
        if(dpr[i][k] == -INFLL){
            cerr<<".";
        }
        else cerr<<dpr[i][k];
        if(k == K)cerr<<endl;
        else cerr<<" ";
    }
    */
}