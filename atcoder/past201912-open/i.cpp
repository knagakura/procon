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
ll dp[1080][1080];
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N,M;
    cin>>N>>M;
    vector<string> S(M);
    
    vector<ll> C(M);
    rep(i,M)cin>>S[i]>>C[i];

    rep(i,1050)rep(j,1050){
        dp[i][j] = INF*1e5;
    }
    dp[0][0] = 0;
    vector<ll> bitS(M,0);
    rep(i,M){
        rep(j,N){
            //cerr<<S[i][j]<<endl;
            if(S[i][j] == 'Y'){
                bitS[i] = bitS[i] | bit(N-1-j);
            }
        }
    }
    //print(bitS);
    rep(i,M){
        rep(k,bit(N)){
            chmin(dp[i+1][k], dp[i][k]);
            chmin(dp[i+1][bitS[i] | k], dp[i][k] + C[i]);
        }
    }

    /*
    rep(i,M+1){
        rep(j,bit(N)){
            if(dp[i][j] < INF*1e5)cerr<<dp[i][j]<<" ";
        }
        cerr<<endl;
    }*/
    if(dp[M][bit(N)-1] == INF*1e5){
        cout<<-1<<endl;
        return 0;
    }
    cout<<dp[M][bit(N)-1]<<endl;
}