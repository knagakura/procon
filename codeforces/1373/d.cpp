#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define dump(x) cerr<<#x<<": "<<x<<endl;
#define bit(k) (1LL<<(k))
typedef long long ll;
typedef pair<int, int> i_i;
typedef pair<ll, ll> l_l;
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

ll dp[2][200010][10];
void solve(){
    int N;
    cin >> N;
    vector<ll> a(N);
    rep(i, N)cin >> a[i];
    ll ans = 0;
    rep(i,N)if(i%2 == 0)ans += a[i];
    // 数列を二つ作る
    vvec<ll> v(2);
    rep(j,2){
        for(int i = j; i+1 < N; i+= 2){
            if(j == 0){
                v[j].push_back(a[i+1]-a[i]);
            }
            else{
                v[j].push_back(a[i] - a[i+1]);
            }
        }
    }
    //print(v[0]);
    //print(v[1]);
    //dp part
    rep(j,2)rep(i,N+1)rep(k,5)dp[j][i][k] = 0;
    rep(j,2){
        int M = v[j].size();
        rep(i,M){
            //from 0 to 1
            {
                chmax(dp[j][i+1][1], dp[j][i][0] + v[j][i]);
            }
            //from 1 to 1
            {
                chmax(dp[j][i+1][1], dp[j][i][1] + v[j][i]);
                //chmax(dp[j][i+1][1], dp[j][i][1]);
            }
            //from 1 to 2
            {
                chmax(dp[j][i+1][2], dp[j][i][1] + v[j][i]);
            }
        }
    }
    /*
    rep(j,2){
        rep(i,N+1){
            cerr << dp[j][i][0] << " " << dp[j][i][1] << " " << dp[j][i][2] << endl;
        }
    }*/
    ll maxx = 0;
    rep(j,2)rep(i,N+1){
        chmax(maxx, dp[j][i][2]);
    }
    ans += maxx;
    cout << ans << endl;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int t;
    cin >> t;
    while(t--)solve();
}