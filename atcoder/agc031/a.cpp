#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)

typedef long long ll;

const int MOD = 1e9+7;

int main() {
	int N;
	string S;
	cin>>N>>S;
	vector<ll> cnt(26,0);
	rep(i,N){
		cnt[S[i]-'a']++;
	}
	ll ans  = 1;
	rep(i,26){
		if(cnt[i]>0){
			ans*=cnt[i]+1;
			ans%=MOD;
		}
	}
	cout<<ans-1<<endl;
}