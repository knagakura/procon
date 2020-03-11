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

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = (ll)1e9;
const ll INFLL = (ll)1e18;
const ll MOD = (ll)1e9+7;
const double PI = acos(-1.0);

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

/*------------------------------------/
for library*/

/*------------------------------------*/
int A[10][10];
int N;
bool c[10][10];
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    rep(i,3)rep(j,3){
        cin>>A[i][j];
        c[i][j] = false;
    }
    cin>>N;
    rep(i,N){
        int b;
        cin>>b;
        rep(i,3)rep(j,3){
            if(b == A[i][j])c[i][j] = true;
        }
    }

    bool ans = false;
    //行について
    rep(i,3){
        bool ALL = true;
        rep(j,3){
            if(!c[i][j])ALL = false;
        }
        if(ALL){
            ans = true;
        }
    }
    //列について
    rep(j,3){
        bool ALL = true;
        rep(i,3){
            if(!c[i][j])ALL = false;
        }
        if(ALL){
            ans = true;
        }
    }
    //斜めについて
    if(c[0][0] && c[1][1] && c[2][2])ans = true;
    if(c[0][2] && c[1][1] && c[2][0])ans = true;
    if(ans){
        cout<<Yes<<endl;
    }
    else{
        cout<<No<<endl;
    }
}