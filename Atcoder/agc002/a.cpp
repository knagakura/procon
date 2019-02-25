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
	ll a,b;
	cin>>a>>b;
	int c=1;
	string ans;
	if(b-a>1000000000)ans="Zero";

	else{
		for (ll i = a; i <= b; ++i){
			if(i<0)c*=-1;
			if(i==0)c*=0;
		}
		if(c>0)ans="Positive";
		if(c==0)ans="Zero";
		if(c<0)ans="Negative";
	}
	cout<<ans<<endl;
}