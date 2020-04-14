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
int dp[500005][30] = {0};
int main() {
    string S;
    cin>>S;
    int N = S.size();
    rep(i,N){
        //単純に右にシフト
        rep(j,26){
            dp[i+1][j] = dp[i][j];
        }
        //その文字のところだけ+1
        if(S[i]>)
        dp[i+1][S[i]-'a'] = dp[i][S[i]-'a'] + 1;
    }
    rep(i,N){
        int moji = S[i] - 'a';
        int cnt = 0;
        rep(j, moji){
            cnt += dp[i+1][j];
        }
        cerr<<cnt<<endl;
        if(cnt%2 ==0){
            cout<<"Mike"<<endl;
        }
        else{
            cout<<"Ann"<<endl;
        }
    }
    //
    cerr<<"dp"<<endl;
    rep(j, 26)rep(i,N+1){
        if(i == 0){
            cerr<<char('a' + j)<<": ";
        }
        cerr<<dp[i][j];
        if(i == N){
            cerr<<endl;
        }
        else cerr<<" ";
    }
    //
}