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
	int N;
	cin>>N;
	vector<int> A(N);
	rep(i,N)cin>>A[i];
	int mini,Asum,Amin;
	do {
		Amin=inf;
		rep(i,N){
			if(A[i]>0&&Amin>A[i]){
				mini=i;
				Amin=A[i];
			}
		}
		Asum=0;
		rep(i,N){
			if(A[i]>0&&i!=mini){
				A[i]%=Amin;
				Asum+=A[i];
			}
		}
	}while(Asum>0);
	cout<<Amin<<endl;
}