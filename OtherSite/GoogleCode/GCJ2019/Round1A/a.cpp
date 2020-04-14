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
int T,R,C;
int a,ans1,ans2;
void solve(int t){
	cin>>R>>C;
	cout<<"Case #"<<t<<": "<<ans1<<" "<<ans2<<endl;;
}




int main() {
	cin>>T;
	rep1(i,T+1){
		solve(i);
	}
}