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


vector<vector<pair<int,ll>>> G;
vector<ll> dist;

void dfs(int x, int pre,ll d){
    dist[x] = d;
    for(auto nxt: G[x]){
        if(nxt.first == pre)continue;
        dfs(nxt.first, x, d+nxt.second);
    }
}
int main() {
    int N;cin>>N;
    G.resize(N);
    dist.resize(N);
    rep(i,N-1){
        int a,b;ll c;
        cin>>a>>b>>c;
        a--;b--;
        G[a].push_back({b,c});
        G[b].push_back({a,c});
    }
    int Q,K;cin>>Q>>K;
    K--;
    dfs(K, -1, 0);
    rep(i,Q){
    int x,y;cin>>x>>y;
    x--;y--;
    ll ans = dist[x] + dist[y];
    cout<<ans<<endl;
    }
    print(dist);
}