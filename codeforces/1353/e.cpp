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

void solve(){
    int N, K;
    cin >> N >> K;
    string S;
    cin >> S;
    int cnt1 = 0;
    vvec<int> V(K);
    rep(i,N){
        V[i%K].push_back(S[i]-'0');
        cnt1 += S[i] - '0';
    }
    ll ans = INFLL;
    //i番目の分割
    rep(i,K){
        //00...111...000にする最小値 耳DP
        int M = V[i].size();
        vvec<ll> dp(M+1, vec<ll>(3,INFLL));
        dp[0][0] = dp[0][1] = dp[0][2] = 0;
        int tmp = 0;//この区間に含まれる1の数
        //from 0
        rep(j,M){
            tmp += V[i][j];
            {
                //to 0
                chmin(dp[j+1][0], dp[j][0] + V[i][j]);
                //to 1
                chmin(dp[j+1][1], dp[j][0] + (V[i][j]^1));
            }
            //from 1
            {
                // to 1
                chmin(dp[j+1][1], dp[j][1] + (V[i][j]^1));
                // to 2
                chmin(dp[j+1][2], dp[j][1] + V[i][j]);
            }
            //from 2
            {
                // to 2
                chmin(dp[j+1][2], dp[j][2] + V[i][j]);
            }
        }
        ll minn = min({dp[M][0],dp[M][1], dp[M][2]});
        chmin(ans, minn + cnt1 - tmp);
    }
    cout << ans << endl;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int t;
    cin >> t;
    while(t--){
        solve();
    }
}