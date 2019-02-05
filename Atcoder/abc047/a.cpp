#include <bits/stdc++.h>
using namespace std;

int main() {
	string ans = "No";
	int a,b,c;
	cin >> a>>b>>c;
	if(a+b==c or b+c == a or c+a == b){
		ans = "Yes";
	}
	cout << ans << endl;
}