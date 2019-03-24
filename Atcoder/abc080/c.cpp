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

int N;

ll F[105][15];
ll P[105][15];
int main() {
	cin>>N;
	rep(i,N)rep(j,10){
		cin>>F[i][j];
	}
	rep(i,N)rep(j,11){
		cin>>P[i][j];
	}
	ll ans = -INF*10;
	//bit全探索　bitは{0,1, ..., n-1}の2^n通りの部分集合全体の集合を動く
	//足すか足さないかを決めるフラグをbitで表現
	for (int bit = 0; bit < (1<<N); ++bit){
		int c = 0;//部分集合全体の和
		for (int i = 0; i < N; ++i){
			if((bit & (1<<i))&){//i番目の要素を足すようになっていたら
				sum += a[i]; 
			}
	}
	cout<<ans<<endl;
}