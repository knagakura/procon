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

int N;
//下からi桁目まで決めていて、上に繰り上がりを要求するかどうか
ll dp[1001005][2];
void debug(){
    rep(i,N+1){
        rep(j,2){
            cerr<<dp[i][j]<<" ";
        }
        cerr<<endl;
    }
    cerr<<endl;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    string S;
    cin >> S;
    reverse(all(S));
    S += "0";
    N = S.size();
    rep(i,N+1)rep(j,2)dp[i][j] = INF;
    dp[0][0] = 0;
    rep(i,N){
        int d = S[i] - '0';
        rep(j,2){
            for(int k = 0; k < 10; k++){
                int tmpk = k;
                if(j)tmpk--;
                //if(tmpk < 0)continue;
                if(tmpk >= d){
                    chmin(dp[i+1][0], dp[i][j] + k + (tmpk - d));
                }
                else{
                    chmin(dp[i+1][1], dp[i][j] + k + 10 + tmpk - d);
                }
            }
        }
    }
    //debug();
    cout << min(dp[N][0], dp[N][1])<<endl;
}