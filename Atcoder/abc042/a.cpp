#include <bits/stdc++.h>
using namespace std;

int main() {
	string ans = "NO";
	int v[3];
	cin >> v[0]>>v[1]>>v[2];
	if(v[0]*v[1]*v[2]==175){
		ans = "YES";
	}
	cout << ans << endl;
}