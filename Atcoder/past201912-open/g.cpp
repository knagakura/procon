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
int N;
ll a[12][12];
ll ans;
void dfs(int idx, string &g){
    if(idx == N){
        //cerr<<g<<endl;
        vector<vector<int>> v(3);
        rep(i,N){
            v[g[i] - '0'].push_back(i);
        }
        ll score = 0;
        rep(j,3){
            int n = v[j].size();
            rep(k,n)rep(l,n){
                if(k > l)continue;
                score += a[ v[j][k] ][ v[j][l] ];
            }
            //print(v[j]);
        }
        chmax(ans, score);
        return;
    }
    g[idx] = '0';
    dfs(idx + 1,g);
    g[idx] = '1';
    dfs(idx + 1,g);
    g[idx] = '2';
    dfs(idx + 1,g);
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    cin>>N;
    rep(i,N)rep(j,N)a[i][j] = 0;
    for(int i = 0;i < N;i++){
        for(int j = i+1; j < N; j++){
            cin>>a[i][j];
            a[j][i] = a[i][j];
        }
    }
    string g = "";
    rep(i,N)g.push_back('0');
    ans = -INFLL;
    dfs(0,g);
    cout<<ans<<endl;
}