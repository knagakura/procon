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
int N;
ll dp[200010][5];
void solve1(){
    vvec<ll> A(2, vec<ll>(N/2));
    rep(i,N){
        cin >> A[i%2][i/2];
    }
    //print(A[0]);print(A[1]);
    rep(i,N/2+1)rep(j,2)dp[i][j] = -INFLL;
    dp[0][0] = 0;
    rep(i,N/2){
        chmax(dp[i+1][0], dp[i][0] + A[0][i]);
        chmax(dp[i+1][1], dp[i][0] + A[1][i]);
        chmax(dp[i+1][1], dp[i][1] + A[1][i]);
    }
    cout << max(dp[N/2][0], dp[N/2][1]) << endl;
}
ll dp2[200010][5][2];
void solve2(){
    vvec<ll> A(2, vec<ll>(N/2+1));
    rep(i,N){
        cin >> A[i%2][i/2];
    }
    //print(A[0]);print(A[1]);
    rep(i,N/2+2)rep(j,2)rep(k,2)dp[i][j] = -INFLL;
    dp2[0][0][0] = 0;
    dp2[0][0][1] = 0;
    rep(i,N/2+1){
        chmax(dp2[i+1][0][0], dp2[i][0][0] + A[0][i]);
        chmax(dp2[i+1][1][0], dp2[i][0][0] + A[1][i]);
        chmax(dp2[i+1][1][0], dp2[i][1][0] + A[1][i]);

        chmax(dp2[i+1][0][1], dp2[i][0][1] + A[0][i]);
        chmax(dp2[i+1][1][1], dp2[i][0][1] + A[1][i]);
        chmax(dp2[i+1][1][1], dp2[i][1][1] + A[1][i]);

        chmax(dp2[i+1][0][1], dp2[i][0][0]);
        chmax(dp2[i+1][1][1], dp2[i][1][0]);
        chmax(dp2[i+1][1][1], dp2[i][0][0]);
        chmax(dp2[i+1][0][1], dp2[i][1][0]);
    }
    cout << max(dp2[N/2+1][0][1], dp2[N/2+1][1][1]) << endl;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    cin >> N;
    if(N % 2 == 0)solve1();
    else solve2();
}