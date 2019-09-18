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
const int INF = 1e9;
ll dp[100005][4];
int main() {
    string S;   
    cin>>S;
    int N = S.size();
    dp[0][0] = 1;
    //
    rep(i,N){
        if(S[i] == '?'){
            rep(j,4){
                dp[i+1][j] += 3*dp[i][j]%MOD;
            }
            rep(k,3){
                dp[i+1][k+1] += dp[i][k];
                dp[i+1][k+1] %= MOD;
            }
        }
        else{
            rep(j,4){
                dp[i+1][j] += dp[i][j];
                dp[i+1][j] %= MOD;
            }
            dp[i+1][S[i]-'A'+1] += dp[i][S[i]-'A'];
            dp[i+1][S[i]-'A'+1] %= MOD;
        }
    }
    cout<<dp[N][3]%MOD<<endl;

}