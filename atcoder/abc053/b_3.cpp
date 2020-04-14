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
	string S;
	cin>>S;
	int N=S.size();
	int ans=0;
	int a=inf,b=0;
	rep(i,N){
		if(S[i]=='A')a = min(a,i);
		else if(S[i]=='Z')b =max(b,i);
	}
	ans=b-a+1;
	cout<<ans<<endl;
}