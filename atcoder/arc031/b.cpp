#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)

using P = pair<int, int>;		//P.first, P.second

typedef long long ll;
typedef vector<string> vs;

int H =10,W = 10;

int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};
int dist[15][15] = {};

//grid
//BFS
//幅優先探索

bool in(int x, int y){
	return 0<=x&&x<H&&0<=y&&y<W;
}

int main() {
	vs A(H);
	rep(i,10)cin>>A[i];
	queue<P> Q;
/*	Q.push({0,0});
*/
	rep(i,H)rep(j,W){
		dist[i][j] = -1;
		if(A[i][j] == 'o'){
			Q.push({i,j});
			dist[i][j] = 0;
		}
	}
	while(!Q.empty()){
		P p = Q.front();
		Q.pop();
		int x = p.first, y = p.second;
		rep(i,4){
			int nx = x + dx[i], ny = y + dy[i];
			if(!in(nx,ny)||dist[nx][ny]!=-1)continue;
			dist[nx][ny] = dist[x][y]+1;
			Q.push({nx,ny});
		}
	}
	string ans = "NO";
	rep(i,H){
		rep(j,W){
			if(to_string(dist[i][j]).size() == 1){
				cerr<<' ';
			}
			cerr<<dist[i][j];
		}
		cerr<<endl;
	}
	cout<<ans<<endl;
}						