#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }

typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = 1e9;
const ll INFLL = 1e18;
const ll MOD = 1e9+7;
const double PI = acos(-1.0);

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
int N;
vector<vector<pair<int,int>>> G;
vector<int> color;
vector<pair<int,int>> ab;
ll maxc;
/*------------------------------------/
for library*/

/*------------------------------------*/

void dfs(int i, int pre, ll pre_c){
    if(pre == -1){
        int cnt = 1;
        for(auto ni: G[i]){
            color[ni.second] = cnt;
            dfs(ni.first, i, cnt);
            cnt++;
        }
    }
    else{
        int cnt = 1;
        for(auto ni: G[i]){
            if(ni.first == pre)continue;
            if(cnt == pre_c){
                cnt++;
            }
            color[ni.second] = cnt;
            //color[ni.second] = (pre_c == maxc) ? pre_c-1:pre_c + 1;
            dfs(ni.first, i, color[ni.second]);
            cnt++;
        }
    }
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    cin>>N;
    G.resize(N);
    color.resize(N-1);
    rep(i,N-1){
        int a,b; cin>>a>>b;
        a--;b--;
        G[a].push_back({b,i});
        G[b].push_back({a,i});
    }
    maxc = 0;
    int start = 0;
    rep(i,N){
        if(maxc < (ll)G[i].size()){
            chmax(maxc, (ll)G[i].size());
            start = i;
        }
    }
    cout<<maxc<<endl;
    //printpair(ab);
    dfs(start, -1, -1);
    rep(i,N-1){
        cout<<color[i]<<endl;
    }
}