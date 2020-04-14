#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)

using P = pair<int, int>;		//P.first, P.second

typedef long long ll;
typedef vector<string> vs;

int H,W;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};
int dist[1005][1005] = {};

//grid
//BFS
//幅優先探索

bool in(int x, int y){
	return 0<=x&&x<H&&0<=y&&y<W;
}

int main() {
	cin>>H>>W;
	vs A(H);
	rep(i,H)cin>>A[i];
	queue<P> Q;
	Q.push({0,0});
	int bcnt = 0;
	rep(i,H)rep(j,W){
		dist[i][j] = -1;
		if(A[i][j] == '#')bcnt++;
	}
	dist[0][0] = 1;
	while(!Q.empty()){
		P p = Q.front();
		Q.pop();
		int x = p.first, y = p.second;
		rep(i,4){
			int nx = x + dx[i], ny = y + dy[i];
			if(!in(nx,ny)||dist[nx][ny]!=-1||A[nx][ny] !='.')continue;
			dist[nx][ny] = dist[x][y]+1;
			Q.push({nx,ny});
		}
	}
	if(dist[H-1][W-1] == -1){
		cout<<-1<<endl;
		return 0;
	}
	int ans= H*W - bcnt - dist[H-1][W-1];
	cerr<<dist[H-1][W-1]<<endl;
	cout<<ans<<endl;
}						