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

using Edge = pair<int, long long>;
using Graph = vector<vector<Edge>>;

ll d[305][305];
int nxt[305][305];
vector<int> get_path(int start, int goal){
    int cur;
    vector<int> path;
    for(cur = start; cur!=goal; cur = nxt[cur][goal]){
        path.push_back(cur);
    }
    path.push_back(goal);
    return path;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,M,L,Q;
    cin>>N>>M>>L;
    Graph G(N);
    rep(i,M){
        int a,b;
        ll c;
        cin>>a>>b>>c;
        a--;b--;
        /*
        G[a].push_back({b,c});
        G[b].push_back({a,c});
        */
        d[a][b] = d[b][a] = c;
    }
    //初期化
    rep(i,N)rep(j,N){
        nxt[i][j] = j;
    }
    //ワーシャルフロイド
    rep(k,N)rep(i,N)rep(j,N){
        if(d[i][k]+d[k][j]<d[i][j]){
            d[i][j] = d[i][k] + d[k][j];
            //更新
            nxt[i][j] = nxt[i][k];
        }
        
    }
    cin>>Q;
    rep(i,Q){
        int s,t;
        cin>>s>>t;
        auto path = get_path(s,t);
        priority_queue<ll> que;
        int ans = 0;
        int tank = L;
        bool flag = false;
        rep(x,(int)path.size()-1){
            int dist = d[path[x]][path[x+1]];
            while(tank-dist>0){
                if(que.empty()){
                    ans = -1;
                    flag = true;
                    break;
                }
                tank += L;
                que.pop();
                ans++;
            }
            if(flag)break;
            tank -= dist;
            que.push(1);
        }
        cout<<ans<<endl;
    }
}