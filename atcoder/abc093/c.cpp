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
	vector<int> A(3);;
	cin>>A[0]>>A[1]>>A[2];
	sort(all(A));
	int ans = 0;
	if(A[0]%2!=A[1]%2){
		A[2]++;A[1]++;ans++;
	} 
	ans += A[2]-A[1] + (A[2]-(A[0]+A[2]-A[1]))/2;
	cout<<ans<<endl;
}