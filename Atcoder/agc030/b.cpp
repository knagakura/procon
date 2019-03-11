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
	int A,B,C;
	cin>>A>>B>>C;
	int ans = 0;
	ans += B;
	//cout<<ans<<endl;
	ans += min(C,B+1);
	//cout<<ans<<endl;
	C = max(0,C-(B+1));
	//cout<<C<<endl;
	if(C>0){
		ans += min(C,A);
	}
	cout<<ans<<endl;
}