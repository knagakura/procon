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
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;
template< typename T1, typename T2 >
ostream &operator<<(ostream &os, const pair< T1, T2 >& p) {
  os << "{" <<p.first << ", " << p.second << "}";
  return os;
}
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
int M;
vvec<int> G;
vec<int> dp;

void dfs(int s){
    dump(s);
    print(dp);
    for(auto nx: G[s]){
        dp[nx]+=dp[s];
        dfs(nx);
    }
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N, K, C;
    cin >> N >> K >> C;
    string S;
    cin >> S;
    vector<int> v;
    rep(i,N)if(S[i] == 'o')v.push_back(i);
    M = v.size();
    print(v);
    v.push_back(INF);
    dp.resize(M,0);
    G.resize(M);
    vector<bool> start(M,true);
    rep(i,M){
        int nx = upper_bound(all(v),v[i]+C) - v.begin();
        cerr << v[i]+C << " "<<v[nx] << endl;
        if(nx == M)continue;
        start[nx] = false;
        G[i].push_back(nx);
    }
    for(int i = M-1;i >= 0;i--){
        int px = lower_bound(all(v), v[i]-C) - v.begin();
        cerr << i << " " << px << endl;
    }
    print(start);
    rep(i,M){
        cerr<<i;print(G[i]);
    }
    queue<int> q;
    vector<bool> visited(M,false);
    rep(i,M)if(start[i]){
        if(G[i].size() == 0)continue;
        dp[i] = 1;
        //dfs(i);
        q.push(i);
        visited[i] = true;
    }
    while(!q.empty()){
        int s = q.front();
        q.pop();
        for(auto x: G[s]){
            dp[x] += dp[s];
            if(visited[x])continue;
            q.push(x);
            visited[x] = true;
        }
    }
    print(dp);
}