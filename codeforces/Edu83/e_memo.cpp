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
int N;
vector<int> a;
ll dp[505][505];
ll val[505][505];
void debug(vector<vector<int>>& v){
    rep(i,N+1){
        rep(j,N+1){
            if(v[i][j] == INF)cerr<<-1<<" ";
            else cerr<<v[i][j]<<" ";
        }
        cerr<<endl;
    }
    cerr<<endl;
}
ll dfs(int l, int r){
    if(l == r)return INF;
    if(dp[l][r] != INF)return dp[l][r];
    ll res = INF;
    for(int mid = l+1; mid < r;mid++){
        chmin(res, dfs(l, mid) + dfs(mid, r));
        if(dp[l][mid] == 1 && dp[mid][r] == 1 && val[l][mid] == val[mid][r]){
            res = 1;
            val[l][r] = val[l][mid] + 1;
        }
    }
    dp[l][r] = res;
    return res;
}

void solve(){
    cin >> N;
    a.assign(N, 0);
    rep(i,N)cin>>a[i];
    //dp[i][j]: 区間[i,j)についての操作後の長さの最小値
    //val[i][j]: dp[i][j] == 1の場合のみ、その値を記録する

    rep(i,N+1)rep(j,N+1){
        dp[i][j] = INF;
        val[i][j] = -1;
    }
    rep(i, N){
        dp[i][i+1] = 1;
        val[i][i+1] = a[i];
    }
    /*
    for(int len = 2; len <=N; len++){
        for(int l = 0; l < N; l++){
            int r = l + len;
            if(r > N)continue;
            for(int mid = l+1; mid < r; mid++){
                if(dp[l][mid] == 1 && dp[mid][r] == 1 && val[l][mid] == val[mid][r]){
                    dp[l][r] = 1;
                    val[l][r] = val[l][mid] + 1;
                }
                else{
                    chmin(dp[l][r], dp[l][mid] + dp[mid][r]);
                }
            }
        }
    }*/

    cout << dfs(0, N) << endl;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    solve();
}