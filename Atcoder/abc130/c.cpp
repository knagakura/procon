#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)

typedef long long ll;


int main() {
	ll W,H;
	cin>>W>>H;
	ll x,y;
	cin>>x>>y;
	float ans1 = W*H/2.0;
	int ans2 = 0;
	if(2*x == W&& 2*y == H){
		ans2 = 1;
	}
	cout<<ans1<<" "<<ans2<<endl;
}