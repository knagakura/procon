//https://onlinejudge.u-aizu.ac.jp/problems/2015
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
int A[1100][1100];
void debug(){
    cerr<<endl;
    rep(i,20){
        rep(j,20){
            cerr<<A[i][j];
        }
        cerr<<endl;
    }
    cerr<<endl;
}
/*------------------------------------*/

bool solve(){
    int N,M;
    cin>>N>>M;

    rep(i,1001)rep(j,1001){
        A[i][j] = 0;
    }
    if(N == 0 && M == 0)return true;
    int maxh = 0,maxw = 0;
    vector<int> h(N),w(M);
    rep(k,1001)A[0][k]++;
    rep(k,1001)A[k][0]++;
    rep(i,N){
        cin>>h[i];
        if(i > 0)h[i] += h[i-1];
        chmax(maxh,h[i]);
        rep(k,1001){
            A[h[i]][k]++;
        }
    }
    rep(i,M){
        cin>>w[i];
        if(i > 0)w[i] += w[i-1];
        rep(k,1001){
            A[k][w[i]]++;
        }
    }

    //debug();
    ll ans = 0;
    rep(x,1001){
        int a = x;
        int b = 0;
        int cnt = 0;
        while(a <=1000){
            if(A[a][b] == 2)cnt++;
            a++;b++;
        }
        ans += cnt * (cnt-1) / 2;
    }
    rep1(y,1001){
        int a = 0;
        int b = y;
        int cnt = 0;
        while(b <= 1000){
            if(A[a][b] == 2)cnt++;
            a++;b++;
        }
        ans += cnt * (cnt -1) / 2;
    }
    cout<<ans<<endl;
    return false;
}
int main() {
    while(1){
        if(solve())break;
    }
}