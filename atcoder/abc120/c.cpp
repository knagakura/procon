#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)

int main() {
	string S;
	cin>>S;
	int N = S.size();
	int cnt = 0;
	rep(i,N){
		if(S[i] ==  '0')cnt++;
		else cnt--;
	}
	int ans = N-abs(cnt7);
	cout<<ans<<endl;
}