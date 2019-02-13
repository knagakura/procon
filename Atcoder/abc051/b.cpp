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
const int inf = 1e9;

int sx,sy,tx,ty;
vi dx={1,-1,0,0};
vi dy={0, 0,1,-1};

bool visited[2001][2001];
string ans="";


void dfs(int x, int y){
	if(x==tx&&y==ty)return;
	if(visited[x][y]==true)return;
	visited[x][y]=true;
}

int main() {
	cin>>sx>>sy>>tx>>ty;
	sx+=1000;sy+=1000;
	tx+=1000;ty+=1000;

	rep(i,2001)rep(j,2001)
		visited[i][j]=false;


	cout<<ans<<endl;
}