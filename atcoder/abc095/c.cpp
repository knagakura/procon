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
	int A,B,C,X,Y;
	cin>>A>>B>>C>>X>>Y;
	int ans = INF;
	if(X>Y){
	swap(X,Y);//X<=Y
	swap(A,B);
	}
	ans = min(ans,A*X+B*Y);
	ans = min(ans,2*X*C +B*(Y-X));
	ans = min(ans,2*Y*C);
	cout<<ans<<endl;
}