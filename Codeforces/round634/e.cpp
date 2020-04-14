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

void solve(){
    int N;
    cin >> N;
    vec<int> a(N);
    vvec<int> idx(26, vec<int>(N, 0));
    vvec<int> cum(26, vec<int>(N+1, 0));
    vec<int> sz(26,0);
    rep(i,N){
        cin >> a[i];
        a[i]--;
        idx[a[i]][i]++;
        sz[a[i]]++;
        rep(k, 26){
            cum[k][i+1] += cum[k][i] + idx[k][i];
        }
    }
    /*
    rep(k,26)if(sz[k])print(idx[k]);
    rep(k,26)if(sz[k])print(cum[k]);
    print(sz);
    */
    int ans = 0;
    rep(i,N)rep(j,N+1){
        if(i >= j)continue;
        int midmx = 0;
        int lrminmx = 0;
        //cerr <<"i, j: "<< i << " " << j << endl;
        rep(k,26){
            chmax(midmx, cum[k][j] - cum[k][i]);
            int l = cum[k][i];
            int r = sz[k] - cum[k][j];
            chmax(lrminmx, min(l, r));
        }
        //cerr << midmx << " " << lrminmx << endl;
        chmax(ans, midmx + lrminmx*2);
    }
    cout << ans << '\n';
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int t;
    cin >> t;
    while(t--)solve();
}