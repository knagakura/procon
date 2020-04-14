#include <bits/stdc++.h>
using namespace std;

int main() {
	int A,B;
	cin>>A>>B;
	int ans;
	ans = B+A;
	if(B+A>24)ans-=24;
	cout<<ans<<endl;
}