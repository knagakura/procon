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
	int K,T;
	cin>>K>>T;
	vector<int> a(T);
	int maxa = -INF;
	rep(i,T){
		cin>>a[i];
		maxa = max(maxa,a[i]);
	}

	int ans = max(0,maxa - (K-maxa)-1);

	cout<<ans<<endl;
}