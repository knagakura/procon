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
int d[50][50];
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N,M;
    cin>>N>>M;

    vector<int> x(N),y(N),c(N),X(M),Y(M),C(M);
    rep(i,N){
        cin>>x[i]>>y[i]>>c[i];
    }
    rep(i,M){
        cin>>X[i]>>Y[i]>>C[i];
    }
    rep(i,N+M)rep(j,N+M){
        if(i > j)continue;
        if(i < N){
            if(j < N){
                d[i][j] = d[j][i] = abs(x[i]-x[j])+abs(y[i]-y[j]) * (c[i] == c[j] ? 1:10);
            }
            if(j >=N){
                d[i][j] = d[j][i] = abs(x[i]-X[j-N])+abs(y[i]-X[j-N]) * (c[i] == C[j-N] ? 1:10);
            }
        }
        else{
            d[i][j] = d[j][i] = abs(X[i-N]-X[j-N])+abs(Y[i-N]-X[j-N]) * (C[i-N] == C[j-N] ? 1:10);
        }
    }
    rep(i,N+M){
        rep(j,N+M){
            cerr<<d[i][j]<<' ';
        }
        cerr<<endl;
    }
}