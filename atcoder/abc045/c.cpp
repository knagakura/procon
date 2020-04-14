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

int main() {
	string S;
	cin>>S;
	int N = S.size() - 1;
	//bit全探索　bitは{0,1, ..., n-1}の2^n通りの部分集合全体の集合を動く
	//仕切りに+を入れるか入れないかを決めるフラグをbitで表現
	ll ans = 0;//全ての和
	if(N == 0){
		ans = S[0] - '0';
		cout<<ans<<endl;
		return 0;
	}
	for (int bit = 0; bit < (1<<N); ++bit){
		ll sum = 0;
		for (int i = 0; i < N; ++i){
			sum += S[i]-'0';
			if(bit & (1<<i)){//i番目の仕切りに+を入れるようになっていたら
				ans += sum;
				sum = 0;
			}
			else{
				sum *=10;
			}
			if(i == N-1){
				sum += S[N] - '0';
			}
		}
		ans += sum;
	}
	cout<<ans<<endl;
}