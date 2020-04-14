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

int H,W;
vector<string> c(105);
bool reached[105][105];

void dfs(int x,int y){
	if(H<=x||W<=y||c[x][y]=='#')return;
	if(reached[x][y])return;

	reached[x][y] = true;

	dfs(x+1,  y);
	dfs(x  ,y+1);
} 

int main() {
	cin>>H>>W;
	rep(i,H){
		cin>>c[i];
	}

	string ans = ":(";
	dfs(0,0);
	string sample = "";
	rep(i,W)sample+=".";
	bool ok = false;
	rep(i,H){
		if(c[i] == sample)ok = true;
	}
	if(reached[H-1][W-1]&&ok)ans = "Yay!";
	cout<<ans<<endl;
}