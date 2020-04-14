#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)

int main() {
	vector<string> s(3);
	int offset = 'A'-'a';
	rep(i,3)cin>>s[i];
	rep(i,3){
		char a = s[i][0]+offset;
		cout<<a;
	}
	cout<<endl;
}