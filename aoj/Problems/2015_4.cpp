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
const int IMAX = 2000000;
int H[IMAX],W[IMAX];
int X[IMAX],Y[IMAX];
int a[IMAX],b[IMAX];
int N,M;
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    while(1){
        cin>>N>>M;
        if(N==0&&M==0)break;
        rep(i,max(N,M) + 5){
            X[i] = Y[i] = 0;
        }
        rep(i,IMAX){
            a[i] = b[i] = 0;
        }
        rep(i,N){
            cin>>H[i];
            Y[i+1] += H[i] + Y[i];
        }
        rep(i,M){
            cin>>W[i];
            X[i+1] += W[i] + X[i];
        }
        map<int,int> map;
        for(int i = 0; i <= N; i++){
            for(int j = 0; j <= M; j++){
                map[Y[i]-X[j]]++;
            }
        }
        ll ans = 0;
        for(auto p:map){
            ans += p.second * (p.second-1) /2;
        }
        cout<<ans<<endl;
    }
}