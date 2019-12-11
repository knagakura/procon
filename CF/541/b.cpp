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
	int N;
	cin>>N;
	vector<int> a(N+1),b(N+1);
	rep1(i,N+1)cin>>a[i]>>b[i];
	int ans = 1;
	rep(i,N){
		if(min(a[i+1],b[i+1])>=max(a[i],b[i]))
		ans+=min(a[i+1],b[i+1])-max(a[i],b[i])+1;
		if(a[i]==b[i])ans--;
	}
	cout<<ans<<endl;
}