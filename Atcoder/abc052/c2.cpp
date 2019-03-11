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
	int N;
	cin>>N;
	vector<bool> f(N+1);//素数かどうか
	//素数判定
	for (int i = 2; i <= N; ++i){
		bool flag = true;
		for (int j = 2; j < i; ++j){
			if(i%j==0)flag = false;
		}
		if(flag)f[i] = true;
	}

	vector<int> s(N+1);
	for (int i = 0; i <= N; ++i){
		s[i] = 1;
	}

	for (int i = 2; i <= N; ++i){
		int a = i;
		for (int j = 2; j <= i; ++j){
			if(f[j]){
				while(a%j==0){
					s[j]++;
					a/=j;
				}
			}
		}
	}
	ll ans = 1;
	rep(i,N+1){
		ans*=s[i];
		ans%=MOD;
	}
	cout<<ans<<endl;
}