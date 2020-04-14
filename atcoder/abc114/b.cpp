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
	cerr<<S<<endl;
	int ans = inf;
	rep(i,N-2){
		string T = S.substr(i,3);
		int M = stoi(T);
		ans = min(ans, abs(753-M));
		cerr<<S[i]<<endl;
		cerr<<M<<endl;
	}
	cout<<ans<<endl;
}