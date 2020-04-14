#include <bits/stdc++.h>
using namespace std;

int main() {
	int X,A,B;
	cin>>X>>A>>B;
	string ans="delicious";
	if(0<B-A&&B-A<=X)ans="safe";
	else if(B-A>X)ans="dangerous";
	cout<<ans<<endl;
}