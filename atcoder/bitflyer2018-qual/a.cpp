#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)

int main() {
	int A,B;cin>>A>>B;
	int ans=0;
	rep1(i,A+1){
		if(i%B==0)ans=max(ans,i);
	}
	cout<<ans<<endl;
}
