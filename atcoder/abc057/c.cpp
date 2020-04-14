#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)

typedef long long ll;

int cnt_digits(ll X){
	int cnt=0;
	while(X>0){
		X/=10;
		cnt++;
	}
	return cnt;
}

int main() {
	ll N;
	cin>>N;
	int ans=cnt_digits(N);
	rep1(A,1e5+1){
		if(N%A==0){
			ll B=N/A;
			int C=max(cnt_digits(A),cnt_digits(B));
			ans=min(ans,C);
		}
	}
	cout<<ans<<endl;
}