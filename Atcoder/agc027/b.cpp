#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()		//sort(all(vi S)) sort(all(string S))
#define rall(a) (a).rbegin(), (a).rend()
typedef long long ll;
typedef vector<int> vi;
typedef set<int> seti;
typedef vector<string> vs;

const int MOD = 1e9+7;
const int INF = 1e9;

int main() {
	int N,x;
	cin>>N>>x;
	vector<int> a(N);
	int ans = 0,suma = 0;
	rep(i,N){
		cin>>a[i];
		suma+=a[i];
	}
	sort(all(a));
	rep(i,N){
		//cout<<x-a[i]<<endl;
		if(x-a[i]>0&&i==N-1)break;
		else if(x-a[i]<0)break;
		else if(x-a[i]>=0){
			x-=a[i];
			ans++;
		}
	}
	cout<<ans<<endl;
}