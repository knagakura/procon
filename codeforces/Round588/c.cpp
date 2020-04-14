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
vector<vector<int>> G;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,M;
    cin>>N>>M;
    G.resize(N+1);
    map<P, int> map;
    rep(i,M){
        int a,b;
        cin>>a>>b;
        map[{a,b}]++;
        map[{b,a}]++;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    /*
    rep(i,N){
        print(G[i]);
    }
    */
    if(N < 7){
        cout<<M<<endl;
        return 0;
    }
    if(M == 0){
        cout<<0<<endl;
        return 0;
    }
    //ある頂点を繋がっている中の頂点番号と同じと仮定した場合に
    //何個の頂点が繋ぐことができなくなるかを数える
    //頂点全てに対して全ての色を試すので最大で7*6
    //どのの頂点iで、どの色jと繋ぐのがベストかを考える
    int cnt = INF;//置けなくなる頂点数
    rep1(i,N+1){
        auto nowV = G[i];
        int n = G[i].size();
        //print(nowV);
        //print(G[i]);
        //j番目の頂点と同じ色で繋ぐと仮定すると
        rep(j,n){
            //cerr<<j<<endl;
            int cnt1 = 0;
            rep(k,n){
                if(map[{nowV[j],nowV[k]}]>0){
                    //cerr<<nowV[j]<<" "<<nowV[k]<<endl;
                    cnt1++;
                }
            }
            cnt = min(cnt,cnt1);
        }
    }
    //cerr<<cnt<<endl;
    int ans = M-cnt;
    ans = max(ans, 0);
    cout<<ans<<endl;
    return 0;
}