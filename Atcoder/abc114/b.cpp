#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define all(a) (a).begin(),(a).end()

typedef long long ll;
typedef vector<int> vi;
typedef set<int> seti;
typedef vector<string> vs;

const int MOD = 1e9 + 7;
const int inf = 1e8;

int main() {
	string S;
	cin>>S;
	int N = S.size();
	cout<<S<<endl;
	int ans = inf;
	rep(i,N-2){
		S.substr(i,)
		int M = 100*int(S[i+2])+10*int(S[i+1])+int(S[i]);
		ans = min(ans, abs(753-M));
		cout<<S[i]<<endl;
		cout<<M<<endl;
	}
	cout<<ans<<endl;
}