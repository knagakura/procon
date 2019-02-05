#include <bits/stdc++.h>
using namespace std;

int main() {
	int ans=0;
	int A,B,C;
	cin >> A>>B>>C;
	ans+=(A*B+B*C+C*A)*2;
	cout << ans << endl;
}