#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()

const int inf = 1e9;

int main() {
	int N;
	cin>>N;
	vector<int> a(N);
	rep(i,N) cin>>a[i];
	int ans=inf;
	for (int A = -100; A <= 100; ++A){
		int cost=0;
		rep(i,N){
			cost+=(a[i]-A)*(a[i]-A);
		}
		ans=min(ans,cost);
	}
	cout<<ans<<endl;
}