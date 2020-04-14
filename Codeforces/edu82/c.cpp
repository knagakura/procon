#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define dump(x) cerr<<#x<<": "<<x<<endl;
#define bit(k) (1LL<<(k))
#define Yes "Yes"
#define No "No"
#define YES "YES"
#define NO "NO"
typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = (ll)1e9;
const ll INFLL = (ll)1e18+1;
const ll MOD = (ll)1e9+7;
const double PI = acos(-1.0);
/*
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const string dir = "DRUL";
*/
int g[30][30];
int visited[30];
int visits[30];
vector<vector<int>> G;
vector<int> ans(110);
void dfs(int cur, int pre){
    visits[cur]++;
    if(visited[cur])return;
    visited[cur] = true;
    for(auto nxt: G[cur]){
        if(nxt == pre)continue;
        dfs(nxt, cur);
    }
    return;
}

void dfs2(int cur, int pre, int depth){
    if(visited[cur])return;
    visited[cur] = true;
    ans[depth] = cur;
    //cout<<char(cur + 'a');
    for(auto nxt: G[cur]){
        if(nxt == pre)continue;
        dfs2(nxt, cur, depth+1);
    }
    return;
}

void solve(){
    rep(i,30)rep(j,30)g[i][j] = 0;
    G.assign(30, vector<int>());
    ans.assign(30, -1);

    string s;
    cin>>s;
    int N = s.size();
    
    if(N == 1 || N == 2){
        cout<<YES<<endl;
        rep(i,30){
            cout<<char(i + 'a');
        }
        cout<<endl;
        return;
    }

    rep(i,N-1){
        int t = s[i] - 'a';
        int u = s[i+1] - 'a';
        g[t][u] = g[u][t] = 1;
    }
    
    rep(i,30)rep(j,30){
        if(i >= j)continue;
        if(g[i][j] == 1){
            G[i].push_back(j);
            G[j].push_back(i);
        }
    }
    rep(i,30)visited[i] = false;
    //グラフの閉路検出
    rep(i,30)visits[i] = 0;
    rep(i,30){
        if(visited[i])continue;
        dfs(i,-1);
    }
    rep(i,30){
        if(visits[i] > 1){
            cout<<NO<<endl;
            return;
        }
    }
    bool one = false;
    rep(i,30){
        if(G[i].size() >= 3){
            cout<<NO<<endl;
            return;
        }
        if(G[i].size() == 1){
            one = true;
        }
    }
    if(!one){
        cout<<NO<<endl;
        return;
    }
    /*
    rep(i,30){
        cerr<<char(i + 'a');print(G[i]);
    }*/
    cout<<YES<<endl;
    rep(i,30)visited[i] = false;
    rep(i,30){
        if(G[i].size() == 1){
            dfs2(i, -1, 0);
            /*
            rep(j,30){
                if(!visited[j]){
                    cout<<char(j + 'a');
                }
            }
            cout<<endl;
            return;
            */
        }
    }
    vector<bool> used(30,false);
    rep(i,30){
        if(ans[i] == -1)continue;
        used[ans[i]] = true;
    }
    rep(i,30){
        if(ans[i] != -1){
            cout<<char(ans[i] + 'a');
        }
    }
    rep(i,26){
        if(used[i])continue;
        cout<<char(i + 'a');
    }
    cout<<endl;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int q;
    cin>>q;
    while(q--){
        solve();
    }
}