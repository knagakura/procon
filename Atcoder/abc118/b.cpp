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
const int inf = 1e9;

int main() {
	int N,M;
	cin>>N>>M;
	vector<int> K(N);
	int A[100][100];
	rep(i,N){
		cin>>K[i];
		rep(j,K[i]){
			cin>>A[i][j];
			A[i][j]--;
		}
	}
	vector<int> ans(M);
	rep(i,N)rep(j,K[i]){
		ans[A[i][j]]++;
	}
	int cnt=0;
	rep(i,M){
		if(ans[i]==N)cnt++;
	}
	cout<<cnt<<endl;
}