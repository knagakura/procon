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
	int A,B,N;
	string X;
	cin>>A>>B>>N>>X;
	rep(i,N){
		if(X[i]=='S')A=max(0,A-1);
		else if (X[i]=='C')B=max(0,B-1);
		else if (X[i]=='E'){
			if(A>=B)A=max(0,A-1);
			else B=max(0,B-1);
		}
	}
	cout<<A<<endl;
	cout<<B<<endl;
}