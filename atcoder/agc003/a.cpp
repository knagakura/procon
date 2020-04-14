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
	string S;
	cin>>S;
	int n=0,s=0,w=0,e=0;
	rep(i,S.size()){
		if(S[i]=='N')n++;
		if(S[i]=='W')w++;
		if(S[i]=='S')s++;
		if(S[i]=='E')e++;
	}
	string ans="Yes";
	if(n>0 and s==0)ans="No";
	if(n==0 and s>0)ans="No";
	if(w>0 and e==0)ans="No";
	if(w==0 and e>0)ans="No";
	cout<<ans<<endl;
}