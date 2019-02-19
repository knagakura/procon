#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()		//sort(all(vi S)) sort(all(string S))

typedef long long ll;
typedef vector<int> vi;
ty;
pedef set<int> seti;
typedef vector<string> vs;

const int MOD = 1e9+7;
const int inf = 1e9
int main() {
	int N;
	string S;
	cin>>N>>S;
	int cnt=0,ans=0;
	rep(i,N){
		if(S[i]=='I')cnt++;
		else cnt--;
		ans=max(ans,cnt);
	}
	cout<<ans<<endl;
}