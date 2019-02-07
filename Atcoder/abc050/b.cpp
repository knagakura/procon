#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
	string ans = "No";
	int N;
	cin >> N;
	vector<int> L(N);
	rep(i,N) cin >> L[i];
	sort(all(L));
	ll sum = 0;
	rep(i,N-1)sum+=L[i];
	if(sum>L[N-1]) ans = "Yes";
	cout << ans << endl;
}
