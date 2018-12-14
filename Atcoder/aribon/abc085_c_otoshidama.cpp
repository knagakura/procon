#include <bits/stdc++.h>
	using namespace std;

int main() {
	int ans = 0;
	int N,Y;
	cin >> N >> Y;

	for (int i = 0; i < N+1; ++i){
		for (int j = 0; j < N+1; ++j){
			int k = Y - i*10000 - j* 5000;
			if (k >= 0 and i + j + k/1000 == N){
				cout << i << " " << j<< " " << k/1000 << endl;
				ans++;
				return 0;
			}
		}
	}
	if (ans == 0){
		cout << -1 << " " << -1 << " " << -1 << endl;
		return 0;
	}
}	