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
int T,N;
int a,ans1,ans2;
void solve(int t){
	cin>>N;
	int x = 1;
	ans1 = 0;
	int n = N;
	while(N){
		a = N%10;
		if(a==4)ans1 += (a-1)*x;
		N /= 10;
		x *= 10;
	}
	ans2 = n-ans1;
	cout<<"Case #"<<t<<": "<<ans1<<" "<<ans2<<endl;;
}
int main() {
	cin>>T;
	rep1(i,T+1){
		solve(i);
	}
}