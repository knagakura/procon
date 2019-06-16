#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()		//sort(all(vi S)) sort(all(string S))
#define push_back pb
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }

using P = pair<int, int>;		//P.first, P.second
typedef long long ll;
typedef vector<int> vi;
typedef set<int> seti;
typedef vector<string> vs;

const int MOD = 1e9+7;
const int INF = 1e9;
int H,W;
int dx[4] = {-1,1,0,0};
int dy[4] = {0,0,1,-1};
int dist[1005][1005] = {};
bool in(int x, int y){
	return 0<=x&&x<H&&0<=y&&y<W;
}

//grid
//BFS
//幅優先探索

int main() {
	cin>>H>>W;
	vs A(H);
	queue<P> Q;
	rep(i,H)cin>>A[i];
	rep(i,H)rep(j,W){
		dist[i][j] = -1;
		if(A[i][j] == '#'){
			Q.push({i,j});
			dist[i][j]  = 0;
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
	int ans= 0;
	rep(i,H)rep(j,W){
		ans = max(ans,dist[i][j]);
	}
	cout<<ans<<endl;
}						