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
char c[111][111];
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int A,B;
    cin>>A>>B;
    rep(i,50)rep(j,100)c[i][j]    = '.';
    rep(i,50)rep(j,100)c[i+50][j] = '#';
    int cntb = 1;
    rep(i,50)rep(j,100){
        if(cntb == B){
            i = j = INF;
            continue;
        }
        if(i % 2 == 0 && j % 2 == 0){
            c[i][j] = '#';
            cntb++;
        }
    }
    int cntw = 1;
    rep(i,50)rep(j,100){
        if(cntw == A){
            i = j = INF;
            continue;
        }
        if((i+50) % 2 == 1 && j % 2 == 0){
            c[i+50][j] = '.';
            cntw++;
        }
    }
    cout<<100<<" "<<100<<endl;
    rep(i,100){
        rep(j,100){
            cout<<c[i][j];
        }
        cout<<endl;
    }
}