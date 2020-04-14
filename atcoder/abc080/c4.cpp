#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }

typedef long long ll;

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = 1e9;
const ll INFLL = 1e18;
const ll MOD = 1e9+7;

const double PI = acos(-1.0);

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    int N;
    cin>>N;
    vector<vector<int>> F(N,vector<int>(10,0));
    vector<vector<int>> P(N,vector<int>(11,0));
    rep(i,N)rep(j,10)cin>>F[i][j];
    rep(i,N)rep(j,11)cin>>P[i][j];
    // 全探索 --- bit は {0, 1, ..., n-1} の 2^n 通りの部分集合全体を動きます。
    //bit = 店の開き方
    ll ans = -INFLL;
    for (int bit = 1; bit < (1<<10); ++bit){
        /* bit で表される集合の処理を書く */
        //ある店との競合
        ll d = 0;
        rep(i,N){
            int cnt = 0;
            //j番目のbitが立っていて、F[i][j]も立っているか
            for(int j = 0; j < 10;j++){
                if(F[i][j] == 1 && (bit>>j & 1)){
                    cnt++;
                }
            }
            d += P[i][cnt];
        }
        chmax(ans, d);
    }
    cout<<ans<<endl;
}