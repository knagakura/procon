#include <bits/stdc++.h>
using namespace std;

int main() {
	int K, S;
	cin >> K >> S;
	int ans;
	ans = 0;
	for (int i = 0; i < K+1; ++i){
		for (int j = 0; j < K+1; ++j){
			int k = S - i - j;
			if (0 <= k and k <=K){
				ans++;
			}
		}
	}
	cout << ans << endl;
}