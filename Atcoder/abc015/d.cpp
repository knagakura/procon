#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()		//sort(all(vi S)) sort(all(string S))

typedef long long ll;
typedef vector<int> vi;
typedef set<int> seti;
typedef vector<string> vs;

const int MOD = 1e9+7;
const int INF = 1e9;

int W,N,K;
vector<int> A(55),B(55);
//幅がW以下で、枚数がK以下における重要度Bの合計値の最大
//W以下かつK以下で実現できる重要度の最大値
//dp[N][W][K];
int dp[55][10005][55];
int main() {
	cin>>W>>N>>K;
	rep(i,N)cin>>A[i]>>B[i];
	rep(i,N){
		rep(w,W+1){
			rep(k,K+1){
				//幅A[i]で重要度B[i]のスクショを追加できるか
				//追加できたら追加して、その前の状態における最大値と比較して更新していく
				if(w+A[i]<=W&&k+1<=K){
					dp[i+1][w+A[i]][k+1] = max(dp[i+1][w+A[i]][k+1],dp[i][w][k] + B[i]);
				}
				//追加できる場合もできない場合も、下に下ろすのは忘れずに
				dp[i+1][w][k] =max(dp[i+1][w][k],dp[i][w][k]);
			}
		}
	}
	int ans = 0;
	rep(i,N+1)rep(w,W+1)rep(k,K+1){
		ans = max(ans,dp[i][w][k]);
	}
	cout<<ans<<endl;
}