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
vector<int> color;
vector<int> dist;
void dfs(int x, int pre, int c){
    color[x] = c;
    for(auto nxt:G[x]){
        if(color[nxt]!=INF||nxt==pre)continue;
        dfs(nxt, x, c);
    }
}
void dfs_dist(int x, int pre, int d){
    dist[x] = d;
    for(auto nxt: G[x]){
        if(nxt==pre)continue;
        dfs_dist(nxt, x, d+1);
    }
}
int main() {
    int N;
    cin>>N;
    G.resize(N);color.resize(N);dist.resize(N);
    rep1(i,N)color[i] = INF;
    color[0] = 1;
    color[N-1] = 0;
    rep(i,N-1){
        int a,b;
        cin>>a>>b;a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(0,-1,color[0]);
    rep(i,N){
        if(color[i]==INF)color[i]=0;
    }
    dfs_dist(0,-1,0);
    int cntb = 0;
    rep(i,N){
        if(color[i] == 1){
            cntb++;
        }
    }
    int aida = dist[N-1]-1;
    cerr<<aida<<endl;
    if(aida%2 == 0){
        cntb -= aida/2;
    }
    else{
        cntb -= (aida-1)/2;
    }
    int cntw = N - cntb;
    if(cntb > cntw){
        cout<<"Fennec"<<endl;
    }
    else{
        cout<<"Snuke"<<endl;
    }
    //print(color);print(dist);
    //cerr<<cntb<<" "<<cntw<<endl;
}