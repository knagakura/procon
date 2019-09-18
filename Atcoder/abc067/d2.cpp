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
vector<vector<int>> G;
//dist[0][i]　N-1（白）からの距離
//dist[1][i] 0（黒）からの距離
int dist[2][100005];
void dfs(int c, int x, int pre, int d){
    dist[c][x] = d;
    for(auto nxt: G[x]){
        if(nxt==pre)continue;
        dfs(c, nxt, x, d+1);
    }
}
int main() {
    int N;
    cin>>N;
    G.resize(N);
    rep(i,N-1){
        int a,b;
        cin>>a>>b;a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(1,0,-1,0);
    dfs(0,N-1,-1,0);
    int cntb = 0;
    rep(i,N){
        if(dist[0][i]>=dist[1][i]){
            cntb++;
        }
    }
    int cntw = N - cntb;
    if(cntb>cntw){
        cout<<"Fennec"<<endl;
    }
    else{
        cout<<"Snuke"<<endl;
    }
}