#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//Nは桁数が大きい場合があるので文字列として受け取る
string N;
int K;
vector<int> n;  //Nの各桁の数字を格納するベクター
int dp[200][2][200];

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
    ll ans = dp[l][0][K] + dp[l][1][K];
    cout << ans << endl;
    return 0;
}