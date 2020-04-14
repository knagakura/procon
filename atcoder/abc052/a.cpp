#include <bits/stdc++.h>
using namespace std;

int main() {
	int ans;
	int A,B,C,D;
	cin >> A >>B>>C>>D;
	ans = A*B;
	if(A*B<C*D){
		ans = C*D;
	}
	cout << ans << endl;
}