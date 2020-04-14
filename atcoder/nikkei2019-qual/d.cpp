#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()

#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define dump(x) cerr<<" "<<#x<<"="<<x

#define bit(k) (1LL<<(k))

typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = (ll)1e9;
const ll INFLL = (ll)1e18;
const ll MOD = (ll)1e9+7;
const double PI = acos(-1.0);

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

/*------------------------------------/
for library*/

/*------------------------------------*/

vector<vector<int>> G;
bool edge_used[100100];
bool v_visited[100100];
map<pair<int,int>, int> mp;

void dfs(int from, int to){
    if(v_visited[to]){
        edge_used[mp[{from, to}]] = false;
        return;
    }
    v_visited[to] = true;
    print(G[to]);
    for(auto nx:G[to]){
        dfs(to, nx);
    }
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N,M;
    G.resize(N);
    rep(i,N+1){
        v_visited[i] = false;
        edge_used[i] = true;
    }
    cin>>N>>M;

    vector<pair<int, int>> edge(N-1+M);
    rep(i,N-1+M){
        int a,b;
        cin>>a>>b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
        mp[{a,b}] = i;
        mp[{b,a}] = i;
        edge.push_back({a,b});
    }
    dfs(-1,0);
    vector<vector<int>> G2(N);
    int cnt = 0;
    for(int i = 0; i < N-1+M;i++){
        if(edge_used[i]){
            G2[edge[i].first].push_back(edge[i].second);
            G2[edge[i].second].push_back(edge[i].first);
            cnt++;
        }
    }
    cerr<<"M, cnt: "<<M<<" "<<cnt<<endl;
    rep(i,N){
        print(G2[i]);
    }
}