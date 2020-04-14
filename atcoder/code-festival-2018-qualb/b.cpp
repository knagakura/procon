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
	int N,X;
	cin>>N>>X;
	vector<int> a(N),b(N);
	int maxb = -INF;
	rep(i,N){
		cin>>a[i]>>b[i];
		maxb = max(maxb,b[i]);
	}
	int ans = maxb*X;
	rep(i,N)ans+=a[i]*b[i];
	cout<<ans<<endl;
}