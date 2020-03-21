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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N,M;
    cin >> N >> M;
    string S[M];
    ll C[M];
    rep(i,M){
        cin >> S[i] >> C[i];
    }

    ll dp[M+5][3000];
    rep(i,M+1)rep(j, bit(N)+1)dp[i][j] = INFLL;
    dp[0][0] = 0;
    rep(i,M){
        for(int j = 0; j < bit(N); j++){
            int nxtbit = j;
            rep(k,N){
                if(S[i][k] == 'Y'){
                    int kbit = bit(k);
                    nxtbit = (nxtbit | kbit);
                }
            }
            chmin(dp[i+1][nxtbit], dp[i][j] + C[i]);
            chmin(dp[i+1][j], dp[i][j]);
        }
    }
    /*
    rep(i,M+1){
        rep(j,bit(N)){
            cerr << i << " " << j <<" " <<dp[i][j] << endl;
        }
    }*/
    cout << (dp[M][bit(N)-1] == INFLL ? -1 : dp[M][bit(N) - 1]) << endl;
}