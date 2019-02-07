#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)

int main() {
	int ans=0;
	string N;
	cin >> N;
	rep(i,N.size())if(N[i] == '2')ans++;
	cout << ans << endl;
}