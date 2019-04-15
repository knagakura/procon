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
	vector<int> A(N);
	rep(i,N-1)cin>>A[i];
	int suma = 0;
	rep(i,N-1)suma+=A[i];
	int ans = suma/T+1;
	if(suma%T == 0)ans--;
	cout<<ans<<endl;
}