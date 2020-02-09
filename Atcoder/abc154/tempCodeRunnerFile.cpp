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

//Nは桁数が大きい場合があるので文字列として受け取る
string N;
int K;
vector<int> n;  //Nの各桁の数字を格納するベクター
ll dp[100][2][200];

int main(){
    cin>>N>>K;

    //ベクターnを構成
    for(auto a : N){
        n.push_back(a-'0');
    }
    int l = N.size();  //nの長さ

    dp[0][0][0] = 1;  //初期条件。他は0で初期化されている
    for(int i = 0; i < l; i++){
        for(int smaller = 0; smaller < 2; smaller++){
            for(int j = 0; j <= 3; j++){
                for(int x = 0; x <= (smaller ? 9 : n[i]); x++){
                    if(x != 0){
                        dp[i + 1][smaller || x < n[i]][j+1] += dp[i][smaller][j];     
                    }
                    else{
                        dp[i + 1][smaller || x < n[i]][j] += dp[i][smaller][j];          
                    }
                    
                }
            }
        }
    }
    cout << dp[l][0][K] + dp[l][1][K] << endl;

    return 0;
}