#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()

int main() {
	int H,W;
	cin>>H>>W;
	vector<string> S(H);
	rep(i,H){
		cin>>S[i];
	}
	string ans = "Yes";
	rep1(i,H-1)rep1(j,W-1)
	if(S[i][j] == '#')
	if(S[i+1][j]!='#'&&S[i][j+1]!='#'&&S[i-1][j]!='#'&&S[i][j-1]!='#')
	ans = "No";
	cout<<ans<<endl;
}