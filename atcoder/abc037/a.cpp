#include <bits/stdc++.h>
using namespace std;

int main() {
	int ans;
	int a,b,c;
	cin >> a>>b>>c;
	int d = min(a,b);
	ans = int(c / d);
	cout << ans << endl;
}