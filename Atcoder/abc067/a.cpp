#include <bits/stdc++.h>
using namespace std;

int main() {
	int A,B;
	cin>>A>>B;
	string ans="Impossible";
	if(A%3==0|B%3==0|(A+B)%3==0)ans="Possible";
	cout<<ans<<endl;
}