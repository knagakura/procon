#include <bits/stdc++.h>
using namespace std;

int main() {
	string ans ="Worse";
	int x,y;
	cin >> x>>y;
	if (x<y){
		ans = "Better";
	}
	cout << ans << endl;
}