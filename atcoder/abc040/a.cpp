#include <bits/stdc++.h>
using namespace std;

int main() {
	int ans;
	int n,x;
	cin >> n>>x;
	ans = min(x-1,n-x);
	cout << ans << endl;
}