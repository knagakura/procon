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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N;
    cin>>N;
    vector<vector<ll>> a(2,vector<ll>(N));
    rep(i,N){
        cin>>a[0][i];
        a[1][i] = a[0][i];
    }
    if(N == 1){
        cout<<a[0][0]/2<<endl;
        return 0;
    }
    ll ans[2] = {0,0};
    reverse(all(a[1]));
    rep(i,2){
        rep(j,N-1){
            if((a[i][j] + a[i][j+1]) % 2 == 0){
                ans[i] += (a[i][j] + a[i][j+1]) / 2;
                a[i][j] = a[i][j+1] = 0;
            }
            else{
                ans[i] += (a[i][j] + a[i][j+1]) / 2;
                a[i][j] = 0;
                a[i][j+1] = min(1LL,a[i][j+1]);
            }
            //print(a[i]);
        }
        //cerr<<endl;
    }

    //cerr<<ans[0]<<" "<<ans[1]<<endl;
    cout<<max(ans[0],ans[1])<<endl;
}