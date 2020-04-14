#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()

typedef long long ll;
typedef vector<int> vi;
typedef set<int> seti;
typedef vector<string> vs;

const int MOD = 1e9+7;
const int inf = 1e9;

int main() {
	int x,y;
	cin>>x>>y;
	string ans ="No";
	seti g1={1,3,5,7,8,10,12},g2={4,6,9,11},g3 ={2};
	if(g1.count(x)&&g1.count(y))ans="Yes";
	else if(g2.count(x)&&g2.count(y))ans="Yes";
	else if(g3.count(x)&&g3.count(y))ans="Yes";
	cout<<ans<<endl;
}