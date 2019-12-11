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
/*
多点間最短距離を求めるO(V^3)のアルゴリズム。
距離行列dist[MAX_N][MAX_N]が必要。初期化しておく。
※0-indexにしておく。
~使った問題~
D - Candidates of No Shortest Paths
https://atcoder.jp/contests/abc051/tasks/abc051_d
*/
/*
rep(i,N)rep(j,N){
    if(i == j)dist[i][j] = 0;
    else dist[i][j] = INF;
}
rep(k,N)rep(i,N)rep(j,N){
        dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
}
*/
/*------------------------------------*/

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);


    ll M,R;
    cin>>M>>R;

    //前処理
    //多点間最短距離を求める
    int dist[10][10];
    rep(i,10)rep(j,10)dist[i][j] = INF;
    rep(i,10)rep(j,10){
        if(j < i)continue;
        if(i == j)dist[i][j] = 0;
        if(i == 0&&j == 1){
            dist[i][j] = dist[j][i] = 1;
        }
        if(j-i == 3&&i != 0){
            dist[i][j] = dist[j][i] = 1;
        }
        if(j-i ==1 && i%3!=0){
            dist[i][j]  = dist[j][i]  = 1;
        }
    }
    /*
    rep(i,10){
        rep(j,10){
            cerr<<dist[i][j]<<" ";
        }
        cerr<<endl;
    }*/

    /*  cerr<<endl;
    rep(i,10){
        cerr<<i<<": ";
        rep(j,10){
            cerr<<dist[i][j]<<" ";
        }
        cerr<<endl;
    }
    */
    
    //X = M * a + Rとなるような整数Xを列挙して
    //小さい方からテンキー操作に回数を数えて、
    //最小回数が出るはずなので、その回数以下の桁数まで考え続ける
    //桁数が最小回数を上回ったら終わり
    ll ans = INFLL;
    ll X = R;
    ll SIZE = to_string(R).size();
    ll cntt = -1;
    ll maxcntt = pow(10,SIZE);
    cerr<<maxcntt<<endl;
    while(cntt <= maxcntt){
        string S = to_string(X);
        ll N = S.size();
        ll cnt = N;
        cnt+= dist[S[0]-'0'][0];
        rep(i,N-1){
            cnt+= dist[S[i]-'0'][S[i+1]-'0'];
        }
        cerr<<X<<" "<<cnt<<endl;
        //更新
        chmin(ans, cnt);
        X += M;
        cntt++;
    }
    cout<<ans<<endl;
}