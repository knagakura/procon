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
	int N,L,R;
	cin>>N>>L>>R;
	vi a(N);
	rep(i,N){
		cin>>a[i];
		if(a[i]<L)cout<<L;
		else if(a[i]>R)cout<<R;
		else cout<<a[i];
		if(i!=N-1)cout<<' ';
	}
	cout<<endl;
}