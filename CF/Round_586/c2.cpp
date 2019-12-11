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
    vector<int> ans(N);
    ans[0] = 1;
    char mmin = S[0];
    rep1(i,N){
        if(mmin>=S[i]){
            ans[i] = 1;
            mmin = S[i];
        }
    }
    //print(ans);
    rep(i,N){
        if(ans[i]){
            cout<<"Mike"<<endl;
        }
        else cout<<"Ann"<<endl;
    }
}