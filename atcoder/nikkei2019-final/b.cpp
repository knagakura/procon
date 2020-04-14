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
	int N,M,K;
	cin>>N>>M>>K;
	vector<int> A(N),B(M);
	rep(i,N)cin>>A[i];
	rep(i,M)cin>>B[i];
	int X = 0, Y = 0;
	rep(i,N)X+=A[i] * pow(K,N-1-i);
	rep(i,M)Y+=B[i] * pow(K,M-1-i);
	cout<<X<<endl;
	cout<<Y<<endl;
	if(X==Y)cout<<"same"<<endl;
	if(X>Y) cout<<'X'<<endl;
	if(X<Y) cout<<'Y'<<endl;
}