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
int N,M;
int b[540][540];
char bc[540][540];
int ans[540][540];
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    cin>>N>>M;
    rep(i,N)rep(j,M){
        cin>>bc[i][j];
        b[i][j] = bc[i][j] - '0';
    }
    rep(i,N)rep(j,M){
        int minb = INF;
        //cerr<<i<<" "<<j<<" "<<b[i][j]<<endl;
        rep(k,4){
            int nx = i + dx[k];
            int ny = j + dy[k];
            if(0 <= nx && nx< N && 0 <= ny && ny < M){
                //cerr<<"\t"<<nx<<" "<<ny<<" "<<b[nx][ny]<<endl;
                chmin(minb,b[nx][ny]);
            }
            else{
                minb = 0;
                break;
            }
        }
        ans[i][j] = minb;
        rep(k,4){
            int nx = i + dx[k];
            int ny = j + dy[k];
            if(0 <= nx && nx< N && 0 <= ny && ny < M){
                b[nx][ny] -= minb;
            }
        }
    }
    rep(i,N){
        rep(j,M){
            cout<<ans[i][j];
        }
        cout<<endl;
    }
}