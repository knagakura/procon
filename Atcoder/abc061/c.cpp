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
const int inf = 1e9;

int main() {
	int N,M;
	cin>>N>>M;
	vi a(M),b(M),ans(N);
	rep(i,M){
		cin>>a[i]>>b[i];
		ans[a[i]-1]++;
		ans[b[i]-1]++;
	}
	rep(i,N)cout<<ans[i]<<endl;
}