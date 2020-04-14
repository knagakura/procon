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
	ll N,A,B,ans;
	cin>>N>>A>>B;
	if(B<A)ans=0;
	else if(B==A)ans=1;
	else if(N==1)ans=0;
	else if(N==2)ans=1;
	else{
		ans=1+(N-2)*(B-A);
	}
	cout<<ans<<endl;
}

//4 4 4 6 min
//4 5 4 6 +1
//4 5 5 6 +2
//4 5 6 6 +3
//4 6 6 6 +4
