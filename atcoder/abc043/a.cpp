#include <bits/stdc++.h>
using namespace std;

int main() {
	int ans=0;
	int N;
	cin >> N;
	for (int i = 0; i < N; ++i){
		ans += i+1;
	}
	cout << ans << endl;
}