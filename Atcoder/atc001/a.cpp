#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()		//sort(all(vi S)) sort(all(string S))
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }

using P = pair<int, int>;		//P.first, P.second
typedef long long ll;
typedef vector<int> vi;
typedef set<int> seti;
typedef vector<string> vs;

const int MOD = 1e9+7;
const int INF = 1e9;

//HとWの最大値を入れておく
const int MAX_H = 540;
const int MAX_W = 540;

int H,W;
vs field;

//座標がフィールドに入っているかどうかの判定
bool in (int x, int y){
	return 0<=x&&x<H&&0<=y&&y<W;
}

//上下左右
const int dx4[4] = {0,0,1,-1};
const int dy4[4] = {1,-1,0,0};

//周囲8方向
const int dx8[8] = {0,1,1, 1, 0,-1,-1,-1,};
const int dy8[8] = {1,1,0,-1,-1,-1, 0, 1,};

//探索するときに、すでに訪れたか
bool seen[MAX_H][MAX_W];

//深さ優先探索
//壁に注意
void dfs(int h, int w){
	seen[h][w] = true;
	for (int i = 0; i < 4; ++i){
		int nh = h + dx4[i];
		int nw = w + dy4[i];
		if(!in(nh, nw)) continue;
		if(field[nh][nw] == '#') continue;
		if(seen[nh][nw])continue;
		dfs(nh, nw);
	}
}

int main() {
	cin>>H>>W;
	field.resize(H);
	rep(i,H)cin>>field[i];
	int si = 0,sj = 0;
	int gi = 0,gj = 0;
	rep(i,H)rep(j,W){
		if(field[i][j] == 's'){
			si = i;sj = j;
		}
		if(field[i][j] == 'g'){
			gi = i;gj = j;
		}
	}
	dfs(si,sj);
	string ans = "No";
	if(seen[gi][gj])ans ="Yes";
	cout<<ans<<endl;
}