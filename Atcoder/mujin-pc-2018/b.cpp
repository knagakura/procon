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
	int A;cin>>A;
	string S;cin>>S;int N=S.size();
	string ans="No";
	rep(i,N){
		if(A==0)ans="Yes";
		if(S[i]=='+') A++;
		else A--;
		if(A==0)ans="Yes";
	}
	cout<<ans<<endl;
}