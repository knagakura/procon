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
	int N;
	cin>>N;
	vector<ll> A(N),B(N);
	rep(i,N){
		cin>>A[i]>>B[i];
		A[i]--;B[i]--;
	}
		//iとjがstartとgoalの場合
	//i<=j
	ll sum = 0;
	sort(all(A));
	sort(all(B));
	ll i,j;
	if(N%2==1){
		i = A[N/2];
		j = B[N/2];
	}
	else{
		i = (A[N/2-1]+A[N/2])/2;
		j = (B[N/2-1]+B[N/2])/2;
	}
	for (int k = 0; k < N; ++k){
		if(A[k]<=i&&B[k]<=j)sum+=abs(A[k]-i)*2+abs(i-j);
		else if(A[k]<=i&&j<=B[k])sum+=abs(A[k]-i)*2+abs(i-j)+abs(B[k]-j)*2;
		else if(i<=A[k]&&B[k]<=j)sum+=abs(j-i);
		else if(i<=A[k]&&j<=B[k])sum+=abs(i-j)+abs(B[k]-j)*2;
	}
	cout<<sum<<endl;
}