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
vector<ll> a,d;
int N;
int dfs(int i,int cnt){
    int res = INF;
    if(i - a[i] >=0){
        if(a[i-a[i]] % 2 == a[i] % 2){
            res = dfs(i-a[i],cnt+1);
        }
        else{
            d[i] = cnt+1;
        }
    }
    if(i + a[i] < N){
        if(a[i+a[i]] % 2 == a[i] % 2){
            res = dfs(i+a[i],cnt+1);
        }
        else{
            d[i] = cnt+1;
        }
    }
    d[i] = res;
    return res;
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    cin>>N;
    a.resize(N);
    rep(i,N)cin>>a[i];
    d.assign(N,INF);
    rep(i,N){
        if(i - a[i] >=0 && a[i-a[i]] % 2 != a[i] % 2){
            d[i] = 1;
        }
        if(i + a[i] < N && a[i+a[i]] % 2 != a[i] % 2){
            d[i] = 1;
        }
    }
    print(a);print(d);
    rep(i,N){
        if(d[i] == -1){
            dfs(i,0);
        }
    }
}