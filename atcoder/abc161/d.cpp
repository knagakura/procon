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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    ll K;
    cin >> K;
    auto check = [&](ll X){
        string S = to_string(X);
        int N = S.size();
        //i桁目までで未満フラグj,最後の数字k
        ll dp[N+1][2][10];
        rep(i,N+1)rep(j,2)rep(k,10)
            dp[i][j][k] = 0;
        dp[1][0][S[0]-'0'] = 1;
        rep1(i, S[0]-'0')dp[1][1][i] = 1;
        for(int i = 1; i < N;i++){
            rep1(l, 10)dp[i+1][1][l] += 1;
            rep(j,2)rep(k,10){
                int minn = max(0,k - 1);
                int maxx = min({k+1, (j ? 9:S[i]-'0')});
                for(int x = minn; x <= maxx;x++){
                    dp[i+1][j || x < S[i]-'0'][x] += dp[i][j][k];
                }
            }
        }
        ll cnt = 0;
        rep(j,2)rep(k,10){
            cnt += dp[N][j][k];
        }
        return cnt < K;
    };
    ll ok = 0;
    ll ng = 1e11;
    while(ng - ok > 1){
        ll mid = (ok + ng) / 2;
        if(check(mid))ok = mid;
        else ng = mid;
    }
    cout << ng << endl;
}