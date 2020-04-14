#include <bits/stdc++.h>
using namespace std;

int main() {
	int ans;
	int A,B;
	cin >> A>>B;
	if(B%A == 0){
		ans = int(B/A);
	}
	else{
		ans = int(B/A)+1;
	}
	cout << ans << endl;
}