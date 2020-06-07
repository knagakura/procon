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
ll dp[100010][2];
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N,L;
    cin >> N >> L;
    vec<int> S(L+1,0);//ハードルの有無
    rep(i,N){
        int x;
        cin >> x;
        S[x] = 1;
    }
    ll T[3];
    rep(i,3)cin >> T[i];
    rep(i,L+1)rep(j,2)dp[i][j] = INF;
    dp[0][0] = 0;
    rep(i,L+1){
        //0
        {
            ll cost = T[0] + (S[i+1] ? T[2]:0);
            chmin(dp[i+1][0], dp[i][0] + cost);
        }
        //1
        {
            ll cost = T[0] + T[1] + (S[i+2] ? T[2]:0);
            chmin(dp[i+2][0], dp[i][0] + cost);
            //ジャンプして通過の最小値
            chmin(dp[i+1][1], dp[i][0] + T[0]/2+T[1]/2);
        }
        //2
        {
            ll cost = T[0] + 3*T[1] + (S[i+4] ? T[2]: 0);
            chmin(dp[i+4][0], dp[i][0] + cost);
            //ジャンプ
            for(int k = 1; k <= 3; k++){
                cost = T[0]/2 + T[1]/2 + (k-1)*T[1];
                chmin(dp[i+k][1], dp[i][0] + cost);
            }
        }
    }
    cout << min(dp[L][0],dp[L][1]) << endl;
}