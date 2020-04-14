#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()

typedef long long ll;
typedef vector<int> vi;
typedef set<int> seti;
typedef vector<string> vs;

const int MOD = 1e9 + 7;
const int inf = 1e8;

int main() {
	int N,M,X;
	cin>>N>>M>>X;
	vector<int> A(M);
	int c1=0,c2=0;
	rep(i,M){
		cin>>A[i];
		if(A[i]>X)c1++;
		else if(A[i]<X)c2++;
	}
	cout<<min(c1,c2)<<endl;
}