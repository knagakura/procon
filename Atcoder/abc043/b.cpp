#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)

int main() {
	string s;
	cin>>s;
	string ans="";
	rep(i,s.size()){
		if(s[i]=='B'){
			if(ans.size())
			ans=ans.substr(0,ans.size()-1);
		}
		else ans+=s[i];
	}
	cout<<ans<<endl;
}