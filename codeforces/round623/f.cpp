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
vector<vector<int>> G;
vector<int> color;
vector<ll> dp;
vector<ll> ans;
ll dfs(int cur, int par){
    if(dp[cur] != -1)return dp[cur];
    ll res = color[cur];
    for(auto& nv: G[cur]){
        if(nv == par)continue;
        chmax(res, res + dfs(nv, cur));
    }
    dp[cur] = res;
    return res;
}

void dfs2(int cur, int par) {
    ans[cur] = dp[cur];
    //cerr << cur << " " << par<< endl;
    //print(ans);
    for(auto& nxt: G[cur]){
        if(nxt == par)continue;
        dp[cur] -= max(0LL, dp[nxt]);
        dp[nxt] += max(0LL, dp[cur]);
        //nxtがrootの状態でdfsが開始
        //cerr << "root:" << cur <<" -> " << nxt << endl;
        dfs2(nxt, cur);
        dp[nxt] -= max(0LL, dp[cur]);
        dp[cur] += max(0LL, dp[nxt]);
        //cerr << "root:" << nxt << " -> "<< cur <<endl;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N;
    cin >> N;
    G.resize(N);
    dp.assign(N, -1);
    color.resize(N);
    ans.resize(N);
    rep(i,N){
        cin >>color[i];
        if(color[i] == 0)color[i] = -1;
    }
    rep(i,N-1){
        int a, b;
        cin >> a >> b;
        a--; b--;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    dfs(0, -1);
    dfs2(0, -1);
    //print(color);print(dp);print(ans);
    rep(i,N){
        cout<<ans[i];
        if(i == N-1)cout<<endl;
        else cout << " ";
    }
}