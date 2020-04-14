#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<n;i++)

int main() {
	string ans = "NO";
	vector<int> N(4);
	rep(i,4) cin >> N.at(i);
	sort(N.begin(), N.end());
	if (N[0] == 1 and N[1] == 4 and N[2] == 7 and N[3] == 9){
		ans = "YES";
	}
	cout << ans << endl;
}