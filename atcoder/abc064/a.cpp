#include <bits/stdc++.h>
using namespace std;


int main() {
	int r,g,b;
	cin>>r>>g>>b;
	int x = 100*r+10*g+b;
	string ans="NO";
	if(x%4==0)ans="YES";
	cout<<ans<<endl;
}