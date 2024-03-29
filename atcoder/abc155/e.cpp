#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()

#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define dump(x) cerr<<" "<<#x<<"="<<x

#define bit(k) (1LL<<(k))

typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = (ll)1e9;
const ll INFLL = (ll)1e18;
const ll MOD = (ll)1e9+7;
const double PI = acos(-1.0);

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

/*------------------------------------/
for library*/

/*------------------------------------*/
//dp[i][j]: 下からi桁目まで決めたときに、紙幣の最小値
//（桁iで桁上がりしてるかどうかを持つflag j）
int N;
ll dp[1001001][2];
void debug(){
    cerr<<"---------------------"<<endl;
    rep(i,N){
        rep(j,2){
            cerr<<dp[i][j]<<" ";
        }
        cerr<<endl;
    }
    cerr<<"---------------------"<<endl;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    string S;
    cin>>S;
    reverse(all(S));
    S += '0';
    cerr<<S<<endl;
    N = S.size();
    rep(i,N+1)rep(j,2){
        dp[i][j] = INFLL;
    }
    dp[0][0] = 0;
    rep(i,N)rep(j,2){
        //i桁目に設定する値
        int sita = S[i] - '0';
        rep(k, 10){
            //下の桁で繰り上がりが起きているなら
            //設定した値が少なくなる（前のところで使われている）
            int ue = k;
            if(j)ue--;
            if(ue < 0)continue;
            //設定する値がsi以上
            //桁上がりが起きていない
            if(ue >= sita){
                chmin(dp[i+1][0], dp[i][j] + k + ue - sita);
            }
            else{
                chmin(dp[i+1][1], dp[i][j] + k + (10 + ue - sita));
            }
            //cerr<<i<<" "<<j<<" "<<k<<endl;
            //debug();
        }
    }

    cout<<dp[N][0]<<endl;
}