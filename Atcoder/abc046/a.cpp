#include <bits/stdc++.h>
using namespace std;

int main() {
	int ans = 3;
	int a,b,c;
	cin >>a>>b>>c;
	if (a==b and b==c){
		ans =1;
	}
	else if (a ==b or b==c or c ==a){
		ans =2;
	}
	cout << ans << endl;
}