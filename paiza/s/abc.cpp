#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()		//sort(all(vi S)) sort(all(string S))

typedef long long ll;
typedef vector<int> vi;
typedef set<int> seti;
typedef vector<string> vs;

const int MOD = 1e9+7;
const int INF = 1e9;

int main() {
	int k,s,t;
	cin>>k>>s>>t;
	vector<string> ans(100);
	rep(i,k)ans[i] = "";

	ans[0] = "ABC";
	rep(i,k){
		ans[i+1] += "A";
		ans[i+1] += ans[i];
		ans[i+1] += "B";
		ans[i+1] += ans[i];
		ans[i+1] += "C";
	}
	for (int i = s-1; i < t; ++i){
		cout<<ans[k-1][i];
	}
	cout<<endl;
	cout<<ans[k-1]<<endl;
	rep(i,k)cout<<ans[i].size()<<endl;
}