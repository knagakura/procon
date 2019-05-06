#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	ll X,Y;
	cin>>X>>Y;
	int ans = 0;
	while(X<=Y){
		ans++;
		X*=2;
	}
	cout<<ans<<endl;
}