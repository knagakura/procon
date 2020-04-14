#include <bits/stdc++.h>
using namespace std;

int main() {
	int x,a,b;
	cin>>x>>a>>b;
	char ans = 'A';
	if(abs(a-x)>abs(b-x))ans = 'B';
	cout<<ans<<endl;
}