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
	string ans = "Same";
	if(N>M)ans = "Y";
	if(N<M)ans = "X";
	if(N == M){
		rep(i,N){
			if(A[i]==B[i])continue;
			else if(A[i]>B[i]){
				ans ="Y";
				break;
			}
			else if(A[i]<B[i]){
				ans = "X";
				break;
			}
		}
	}
	cout<<ans<<endl;
}