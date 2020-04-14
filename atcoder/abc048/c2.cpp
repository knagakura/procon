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
	int N,x;
	cin>>N>>x;
	int sumx = (N-1)*x;
	int alr = 0;
	int suma = 0;
	vector<int> a(N);
	rep(i,N)cin>>a[i];

	rep(i,N){
		if(i==0||i==N-1)alr+=a[i];
		else suma +=2*a[i];
	}
	int ans = 0;
	if(sumx>=alr+suma)cout<<ans<<endl;
	cout<<"sumx: "<<sumx<<endl;
	cout<<"alr : "<<alr<<endl;
	cout<<"suma: "<<suma<<endl;
}