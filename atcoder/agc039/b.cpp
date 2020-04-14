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
int s[222][222];
int d[222];
vvec<int> G;
int solve(int s){
    int res = -INF;
    vvec<int> cc(N);
    rep(i,N)d[i] = -1;
    d[s] = 0;
    queue<int> q;
    q.push(s);
    while(!q.empty()){
        int v = q.front();
        q.pop();
        for(int nv: G[v]){
            if(d[nv] != -1)continue;
            d[nv] = d[v] + 1;
        }
    }
    return res;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    cin >> N;
    G.resize(N);
    rep(i,N)rep(j,N){
        cin >> s[i][j];
        if(s[i][j]){
            G[i].push_back(j);
            G[j].push_back(i);
        }
    }
    int ans = -1;
    rep(i,N){
        chmax(ans, solve(i));
    }
    cout << ans << endl;
}