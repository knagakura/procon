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

template < typename T > inline string toString( const T &a ) { ostringstream oss; oss << a; return oss.str(); };
 
long long dp[ 32 ][ 2 ][ 20 ][ 20 ];
// dp[ 決めた桁数 ][ 未満フラグ ][ 4 または 9 を含むか ] := 総数

ll solve( const string &S ){
	const int L = S.size();
	fill( ( long long * )dp, ( long long * )dp + sizeof( dp ) / sizeof( long long ), 0 );
	dp[0][0][0][0] = 1;
	rep(i,L){
        const int D = S[i] - '0';
		rep(j,2)rep(k,10)rep(l,10){
				for ( int d = 0; d <= ( j ? 9 : D ); ++d ){
                    if(i == 0){
                        dp[i+1][j||(d < D)][d][d] += dp[i][j][k][l];
                    }
                    else{
                        dp[i+1][j||(d<D)][d][l] += dp[i][j][k][l];
                    }
				}
		}
	}
    ll ans = 0;
    rep1(a,L+1)rep1(b,L+1)rep(c,2)rep(d,2){
        rep(k,10)rep(l,10){
            ans += dp[a][c][k][l] * dp[b][d][l][k];
        }
    }
    return ans;
}

int main()
{
	long long N;
	cin >> N;
	cout<<solve( toString( N ) )<<endl;
    cerr<<N<<endl;
	return 0;
}