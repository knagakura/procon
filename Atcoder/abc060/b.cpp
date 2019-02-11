#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()

typedef long long ll;
typedef vector<int> vi;
typedef set<int> seti;
typedef vector<string> vs;

const int MOD = 1e9 + 7;
const int inf = 1e8;

int main() {
	int A,B,C;
	cin>>A>>B>>C;
	string ans="NO";
	rep1(i,1e6){
		if((A*i)%B == C){
			ans = "YES";
			break;
		}
	}
	cout<<ans<<endl;
}