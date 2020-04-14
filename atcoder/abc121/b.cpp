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
	int N,M,C;
	cin>>N>>M>>C;
	vector<int> A(M),B(M);
	rep(i,M)cin>>B[i];
	int cnt = 0;
	rep(i,N){
		int ans = C;
		rep(j,M){
			cin>>A[j];
			ans+=A[j]*B[j];
		}
		if(ans>0)cnt++;
	}
	cout<<cnt<<endl;
}