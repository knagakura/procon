#include <bits/stdc++.h>
using namespace std;

int main() {
	int ans;
	int N,K,X,Y;
	cin >> N>>K>>X>>Y;
	if(N<K){
		ans = N*X;
	}
	else{
		ans = K*X + (N-K)*Y;
	}
	cout << ans << endl;
}