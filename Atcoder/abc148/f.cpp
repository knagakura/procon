#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define bit(k) (1LL<<(k))
typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = 1e9;
const ll INFLL = 1e18;
const ll MOD = 1e9+7;
const double PI = acos(-1.0);

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

/*------------------------------------/
for library*/

/*------------------------------------*/

vector<vector<int>> G;
vector<int> du,dv;
int N,u,v;
void input(){
    cin>>N>>u>>v;
    u--;v--;
    G.resize(N);du.assign(N,-1);dv.assign(N,-1);
    rep(i,N-1){
        int a,b;
        cin>>a>>b;
        a--;b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
}
void bfs(int start, vector<int> &d){
    d[start] = 0;
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int x = q.front();
        q.pop();
        for(int nv:G[x]){
            if(d[nv] != -1)continue;
            d[nv] = d[x] + 1;
            q.push(nv);
        }
    }
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    input();
    bfs(u,du);
    bfs(v,dv);
    //print(du);
    //print(dv);
    if(G[u].size() == 1){
        for(int nv:G[v]){
            if(nv == G[u][0]){
                cout<<1<<endl;
                return 0;
            }
        }
    }
    if(G[u].size() == 1 && G[u][0] == v){
        cout<<0<<endl;
        return 0;
    }
    //du[i] < dv[i]最大のdv[i]であるところで捕まるべき
    int ans = 0;
    rep(i,N){
        if(du[i] < dv[i]){
            if(du[i] % 2 == dv[i] % 2){
                chmax(ans, dv[i]-1);
            }
            else{
                chmax(ans, dv[i]-1);
            }
        }
    }
    cout<<ans<<endl;
}