#include <bits/stdc++.h>
using namespace std;

int main() {
	int A,B;
	cin>>A>>B;
	if(A==1)A=14;
	if(B==1)B=14;
	string ans = "Bob";
	if(A>B)ans = "Alice";
	else if(A==B)ans ="Draw";
	cout<<ans<<endl;
}