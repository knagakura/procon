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
        // Xを桁ごとのvectorに変換
        vector<int> vx;
        while(X > 0){
            vx.push_back(X%10);
            X/=10;
        }
        reverse(all(vx));
        //桁数
        int N = vx.size();
        // dp[i][smaller][0以外を一度でも取ったか][最後の数字]
        ll dp[N+1][2][2][10];
        rep(i,N+1)rep(j,2)rep(k,2)rep(l,10)dp[i][j][k][l] = 0;
        //dp[1]のみ特殊なのでここで初期化する
        dp[1][1][0][0] = 1;
        for(int i = 1;i < vx[0];i++) dp[1][1][1][i] = 1;
        dp[1][0][1][vx[0]] = 1;
        //dpの遷移
        for(int i = 1; i < N; i++){
            //0以外を取ってないところからの遷移(k = 0)
            //and l = 0
            dp[i+1][1][0][0] += dp[i][1][0][0];
            rep1(l,10)dp[i+1][1][1][l] += dp[i][1][0][0];

            //0以外を既に取っているところからの遷移(k = 1)
            rep(j,2)rep(l,10){
                int minl = max(0, l-1);
                int maxl = min(l+1, (j ? 9:vx[i]));
                for(int nxt = minl; nxt <= maxl; nxt++){
                    dp[i+1][j || nxt < vx[i]][1][nxt] +=  dp[i][j][1][l];
                }
            }
        }
        ll cnt = 0;
        rep(j,2)rep(l,10)cnt += dp[N][j][1][l];
        return cnt >= K;
    };

    ll ng = 0;
    ll ok = 1e18;
    while(ok - ng > 1){
        ll mid = (ok + ng) / 2;
        if(check(mid))ok = mid;
        else ng = mid;
    }
    cout << ok << endl;
}