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

int solve(ll a){
	int res = 0;
	while(a){
		res += a%10;
		a /= 10;
	}
	return res;
}
int x,y;
int main() {
	int N;
	cin>>N;
	int ans = INF;
	rep1(i,N){
		x = solve(i);
		y = solve(N-i);
		ans = min(ans,x+y);
	}
	cout<<ans<<endl;
}