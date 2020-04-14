#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)

#define bit(k) (1LL<<(k))
typedef long long ll;

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = 1e9;
const ll INFLL = 1e18;

int N;
ll t[30][30];
ll dp[20][100000];
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    while(1){
        cin>>N;
        if(N==0)break;
        //init
        rep(i,30)rep(j,30)t[i][j] = 0;
        rep(i,N+1)rep(j,bit(N+1)){
            dp[i][j] = INFLL;
        }
        dp[0][0] = 0;
        //input
        rep(i,N)rep(j,N+1){
            cin>>t[i][j];
        }
        for(int i = 0;i < N;i++){
            //i個からなので、i個立ってる状態を探して、
            //その状態から一個増やして遷移できるものを探す
            //増やすステージに関して、コストの最小値をとる
            for(int k = 0;k < bit(N);k++){
                int cnt = 0;
                for(int j = 0;j < N;j++){
                    if(k & bit(j))cnt++;
                }
                if(cnt != i)continue;
                for(int j = 0;j < N;j++){
                    if(k & bit(j))continue;
                    ll cost = t[j][0];
                    for(int l = 0;l < N;l++){
                        if(k & bit(l))chmin(cost,t[j][l+1]);
                    }
                    chmin(dp[i+1][k | bit(j)],dp[i][k] + cost);
                }
            }
        }
        cout<<dp[N][bit(N)-1]<<endl;
    }
}