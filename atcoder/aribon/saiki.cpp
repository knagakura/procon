#include <bits/stdc++.h>
using namespace std;

bool dfs(int i, int sum){
	int N,k;
	std::vector<int> a;

	//n個決め終わったら今までの和sumがkと等しいかを返す
	if (i == N) return sum == k;
	//a[i]を使わない場合
	if (dfs(i+1, sum)) return true;

	//a[i]を使う場合
	if (dfs(i+1, sum + a[i])) return true;

	//a[i]を使う使わないに拘わらずkが作れないのでfalseを返す
	return false;
}
	
int main(){
	int N,k;
	cin >> N;
	vector<int> a;
	for (int i = 0; i < N; ++i){
		cin >> a.at(i);
	}
	cin >> k;
	string ans = "No";
	if (dfs(0, 0)){
		ans = "Yes";
	}
	cout << ans << endl;
}

//int main() {
//	solve();
//}
