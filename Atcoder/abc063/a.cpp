#include <bits/stdc++.h>
using namespace std;

int main() {
	int A,B;
	cin>>A>>B;
	int ans=A+B;
	if(A+B>=10){
		cout<<"error"<<endl;
		return 0;
	}
	cout<<ans<<endl;
	return 0;
}