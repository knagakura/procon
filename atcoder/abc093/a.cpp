#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
int main() {
	string S;
	cin>>S;
	string ans="No";
	if(S=="abc"|S=="acb"|S=="bac"|S=="bca"|S=="cab"|S=="cba")ans="Yes";
	cout<<ans<<endl;
}
