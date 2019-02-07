#include <bits/stdc++.h>
using namespace std;

int main() {
	int ans;
	int s;
	cin >> s;
	set<int> st;
	int x = s;
	while(st.count(x) ==0){
		st.insert(x); //集合の中にxを入れる
		if (x%2 ==0)
		{
			x/=2;
		}
		else{
			x = x*3 + 1;
		}
	}
	ans = st.size()+1;
	cout << ans << endl;
}

