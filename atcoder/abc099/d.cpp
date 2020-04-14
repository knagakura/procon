#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define bit(k) (1LL<<(k))
typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = 1e9;
const ll INFLL = 1e18;
const ll MOD = 1e9+7;
const double PI = acos(-1.0);

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

/*------------------------------------/
for library*/

/*------------------------------------*/
int N,C;
int D[55][55];
int c[555][555];
//cnt[i][c]: iにcが何個あるか
int cnt[10][55];
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);


    cin>>N>>C;
    rep(i,C)rep(j,C){
        cin>>D[i][j];
    }
    rep(i,N)rep(j,N){
        cin>>c[i][j];
        cnt[(i+j+2) % 3][c[i][j]-1]++;
    }
    //色i,j,kに塗り直す
    ll ans = INFLL;
    rep(i,C)rep(j,C){
        if(i == j)continue;
        rep(k,C){
            if(i == k || j == k)continue;
            ll tmp = 0;
            rep(m, C){
                tmp += D[m][i] * cnt[0][m];
                tmp += D[m][j] * cnt[1][m];
                tmp += D[m][k] * cnt[2][m];
            }
            chmin(ans, tmp);
        }
    }
    cout<<ans<<endl;
}