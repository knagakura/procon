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
char f[105][105];
int N,Q;
void dbg(){
        rep(i,N){
        rep(j,N){
            cout<<f[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}
/*------------------------------------*/


int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    cin>>N>>Q;
    rep(i,N)rep(j,N)f[i][j] = 'N';
    while(Q--){
        int c;
        cin>>c;
        if(c == 1){
            int a,b;cin>>a>>b;
            a--;b--;
            f[a][b] = 'Y';
        }
        if(c == 2){
            int a;
            cin>>a;
            a--;
            rep(i,N){
                if(f[i][a] == 'Y'){
                    f[a][i] = 'Y';
                }
            }
        }
        if(c == 3){
            int a;
            cin>>a;
            a--;
            vector<bool> d(N,false);
            rep(x,N){
                //aがフォローしているユーザーxに対して
                if(f[a][x] == 'Y'){
                    rep(y,N){
                        if(f[x][y] == 'Y'){
                            //f[a][y] = 'Y';
                            d[y] = true;
                        }
                    }
                }
            }
            rep(y,N){
                if(y == a)continue;
                if(d[y])f[a][y] = 'Y';
            }
        }
        //dbg();
    }

    rep(i,N){
        rep(j,N){
            cout<<f[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}