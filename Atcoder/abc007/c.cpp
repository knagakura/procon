#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)

using P = pair<int, int>;		//P.first, P.second

typedef long long ll;
typedef vector<string> vs;

int H,W;
int sx,sy;
int gx,gy;
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
	cin>>H>>W>>sx>>sy>>gx>>gy;
	sx--;sy--;gx--;gy--;
	vs A(H);
	queue<P> Q;
	Q.push({sx,sy});
	rep(i,H)cin>>A[i];
	rep(i,H)rep(j,W){
		dist[i][j] = -1;
	}
	dist[sx][sy] = 0;
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
	int ans= dist[gx][gy];
	cout<<ans<<endl;
}						