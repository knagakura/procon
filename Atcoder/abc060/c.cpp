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
	int N,T;
	cin>>N>>T;
	vector<int> t(N);
	rep(i,N)cin>>t[i];
	int ans = T;
	rep(i,N-1){
		if(t[i]+T>=t[i+1]){
			ans+=t[i+1]-t[i];
		}
		else{
			ans+=T;
		}
	}
	cout<<ans<<endl;
}