#include <bits/stdc++.h>
using namespace std;

int dfs(int m, int n){
	int ret = 0;
	if(n ==	1) return 1;
	for (int i =0;i<=m;i++){
		ret += dfs(m-1, n-1);
	}
	return ret;
}
int main() {
	int m, n;
	int ret;
	cin >> m >> n;
	dfs(m,n);
	cout << ret << endl;
}