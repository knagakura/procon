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
	vector<ll> a(N);
	rep(i,N)cin>>a[i];
	sort(all(a));
	vector<ll> ans(N);
	if(N%2==0){
		for (int i = 0; 2*i < N; ++i){
			ans[i]=a[2*i];
			ans[N-1-i]=a[2*i+1];
		}
		rep(i,N){
			if(i==N-1)cout<<ans[i]<<endl;
			else cout<<ans[i]<<' ';
		}
	}
	else{
		for (int i = 0; 2*i < N; ++i){
			ans[i]=a[2*i];
			ans[N-1-i]=a[2*i+1];
		}
		ans[N/2]=a[N-1];
		rep(i,N){
			if(i==N-1)cout<<ans[i]<<endl;
			else cout<<ans[i]<<' ';
		}
	}
}