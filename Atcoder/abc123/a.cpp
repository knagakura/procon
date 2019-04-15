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

vector<int> v(10);
int main() {
	rep(i,5)cin>>v[i];
	int k;
	string ans = "Yay!";
	cin>>k;
	rep(i,5)rep(j,5){
		if(abs(v[i]-v[j])>k)ans = ":(";
	}
	cout<<ans<<endl;
}