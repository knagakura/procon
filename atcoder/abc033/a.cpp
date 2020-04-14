#include <bits/stdc++.h>
using namespace std;

int main() {
	string ans = "DIFFERENT";
	int N;
	cin >> N;
	if(N%1111 == 0){
		ans = "SAME";
	}
	cout << ans << endl;
}