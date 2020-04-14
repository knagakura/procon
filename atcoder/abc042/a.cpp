#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define all(a) (a).begin(),(a).end()		//sort(all(vi S)) sort(all(string S))

int main() {
	vector<int> A(3);
	rep(i,3)cin>>A[i];
	sort(all(A));
	string ans = "NO";
	if(A[0] == 5&&A[1] == 5&&A[2] == 7)ans ="YES";

	cout<<ans<<endl;
}