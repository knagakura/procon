#include <bits/stdc++.h>
using namespace std;

int main() {
	int x=0;
	int ans = 0;
	int N;
	cin >> N;
	string S;
	cin >> S;
	for (int i = 0; i < N; ++i){
		if (S[i] == 'I') x++;
		else if (S[i] == 'D') x--;
		if(ans<x) ans = x;
	}
	cout << ans << endl;
}