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
	string S,y,m,d,ans = "Heisei";
	cin>>S;
	//y = S.substr(0,4);
	//m = S.substr(5,2);
	//d = S.substr(8,2);
	//if(y<="2019"&&m<="04"&&d<=30)
	if(S>"2019/04/30")ans ="TBD";
	cout<<ans<<endl;
}