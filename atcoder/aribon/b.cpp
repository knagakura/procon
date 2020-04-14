#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	std::vector<int> vx(N), vy(N);
	double ans = -1.0;
	for (int i = 0; i < N; ++i){
		cin >> vx.at(i) >> vy.at(i);
	}
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < N; ++j){
			if (i < j){
				double d;
				d = sqrt(pow(vx[i]-vx[j], 2.0) + pow(vy[i] - vy[j], 2.0));

				//cout << i << j << d << endl;
				ans =max(ans, d);
			}
		}
	}
	cout << ans << endl;
}