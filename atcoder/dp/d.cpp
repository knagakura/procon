#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)

typedef long long ll;

//入力
int N,W;
vector<ll> w(105);
vector<ll> v(105);

//DP table
//dp[i][j] := i-1 番目までの品物から重さがjを超えないように選んだときの
//価値の総和の最大値
ll dp[105][100005];

int main() {
	cin>>N>>W;
	rep(i,N){
		cin>>w[i]>>v[i];
	}
	rep(i,N)rep(j,W+1){
		//i番目の品物を選ぶとき
		//i + 1行目で、j+w[i]がWを超えないような範囲でdp table を更新していく
		//具体的には、
		if(j+w[i]<=W){
			dp[i+1][j+w[i]] = max(dp[i+1][j+w[i]],dp[i][j]+v[i]);
		}
		//i番目の品物を選ばないとき
		//dp table の価値は変わらず、そのまま下に降りる
		dp[i+1][j] = max(dp[i+1][j], dp[i][j]);
	}
	cout<<dp[N][W]<<endl;
}