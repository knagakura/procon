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
	int H,W;
	string ans="Possible";
	cin>>H>>W;
	vector<string> A(H);
	rep(i,H)cin>>A[i];
	rep(x,H-1)rep(y,W-1){
		if(A[x+1][y]=='#'&&A[x][y+1]=='#')ans="Impossible";
	}
	cout<<ans<<endl;
}
//右だけ、下だけっていうの以外だったらNo