#include <bits/stdc++.h>
using namespace std;

int main() {
	char a,b,ans;
	cin>>a>>b;
	if(a=='H'&&b=='D')ans='D';
	if(a=='H'&&b=='H')ans='H';
	if(a=='D'&&b=='H')ans='D';
	if(a=='D'&&b=='D')ans='H';
	cout<<ans<<endl;
}