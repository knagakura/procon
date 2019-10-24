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

//グラフ上の全ての頂点に対して、数字を割り当てて、
//dominoを一回ずつ使って何個置けるかを計算し
//その最大値を出力する
int N,M;
vector<vector<int>> G;
vector<int> a,b;
//グラフ上の頂点の番号は、dfsでO(6^N)
int dfs(vector<int> v){
    if((int)v.size()==N){
        //処理
        int res = 0;
        int domino[6][6]={};
        rep(i,M){
            int l = v[a[i]];
            int r = v[b[i]];
            //dominoをまだ使っていなければ
            if(domino[l][r]==0){
                res++;
                domino[l][r] = domino[r][l] = 1;
            }
        }
        return res;
    }
    int ans = 0;
    //0-5の数字を割り当てていく
    rep(i,6){
        auto tmp = v;
        tmp.push_back(i);
        ans = max(ans,dfs(tmp));
    }
    return ans;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin>>N>>M;
    G.resize(N);a.resize(M);b.resize(M);
    rep(i,M){
        cin>>a[i]>>b[i];
        a[i]--;b[i]--;
    }
    vector<int> V;
    cout<<dfs(V)<<endl;
}