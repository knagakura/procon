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
const int inf = 1001001001;
int dist[1000005][3];
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N, M;
    cin >> N >> M;
    vvec<int> to(N);
    rep(i,M){
        int a, b;
        cin >> a >> b;
        a--;b--;
        to[a].push_back(b);
    }
    int sv, tv;
    cin >> sv >> tv;
    sv--;tv--;
    queue<pair<int, int>> q;
    q.push({sv,0});
    rep(i,N)rep(j,3){
        dist[i][j] = inf;
    }
    dist[sv][0] = 0;
    while(!q.empty()){
        int v = q.front().first;
        int l = q.front().second;
        q.pop();
        for(int u: to[v]){
            int nl = (l+1)%3;
            if(dist[u][nl] != inf)continue;
            dist[u][nl] = dist[v][l] + 1;
            q.push({u, nl});
        }
    }
    int ans = dist[tv][0];
    if(ans == inf)ans = -1;
    else ans /= 3;
    cout << ans << endl;
}