#include <bits/stdc++.h>
using namespace std;

int main() {
	int a,b,c;
	cin>>a>>b>>c;
	int ans;
	ans=min(a+b,b+c);
	ans=min(ans,c+a);
	cout<<ans<<endl;
}