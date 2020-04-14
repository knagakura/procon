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
int A[15][15];
int N,M,K;
vector<int> ans;
void dfs(int pre,int sum){
    cerr<<sum<<endl;
    if(sum>K)return;
    if(pre == M){
        ans.push_back(sum);
        return;
    }
    for(int j = 0; j < M; ++j){
        dfs(pre+1,sum+A[pre+1][j]);
    }
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    cin>>N>>M>>K;
    rep(i,N)rep(j,M){
        cin>>A[i][j];
    }
    rep(i,M){
        dfs(0,A[0][i]);
    }
    //print(ans);
    sort(all(ans));
    if((int)ans.size()==0){
        cout<<-1<<endl;
        return 0;
    }
    if(ans[0]>K){
        cout<<-1<<endl;
        return 0;
    }
    int res = INF;
    rep(i,int(ans.size())){
        if(K>=ans[i]){
            res = min(res,max(0,K-ans[i]));
        }
    }
    cout<<res<<endl;
}