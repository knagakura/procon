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
const double PI = acos(-1.0);
/*
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const string dir = "DRUL";
*/

ll dp[3001][3001][4][2];
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    ll H, W, K;
    cin >> H >> W >> K;
    vvec<ll> S(H+1, vec<ll>(W+1,0));
    rep(i,K){
        int r, c;
        ll v;
        cin >> r >> c >> v;
        r--;c--;
        S[r][c] = v;
    }
    // rep(i,H+1)print(S[i]);
    rep(i,H)rep(j,W)rep(k,4)rep(l,2)dp[i][j][k][l] = -1;
    dp[0][0][0][0] = 0;
    dp[0][0][1][0] = S[0][0];
    rep(i,H)rep(j,W)rep(k,4)rep(l,2){
        // 横方向
        //　使わない
        chmax(dp[i][j+1][k][0], dp[i][j][k][l]);
        // 使う
        chmax(dp[i][j+1][k+(S[i][j+1] > 0)][0], dp[i][j][k][l] + S[i][j+1]);
        // 縦方向
        // 使わない
        chmax(dp[i+1][j][0][1], dp[i][j][k][l]);
        // 使う
        chmax(dp[i+1][j][(S[i+1][j] > 0)][1], dp[i][j][k][l] + S[i+1][j]);
    }
    ll ans = 0;
    rep(i,H)rep(j,W)rep(k,4)rep(l,2)chmax(ans, dp[i][j][k][l]);
    cout << ans << endl;
}

