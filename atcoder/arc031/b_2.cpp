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
int H = 10;
int W = 10;
bool in (int x, int y){
	return 0<=x&&x<H&&0<=y&&y<W;
}
int dx[4] = {0,0,1,-1};
int dy[4] = {1,-1,0,0};

bool seen[10][10];
vs A(H);
int cnt;
void dfs(int h, int w){
	seen[h][w] = true;
	for (int i = 0; i < 4; ++i){
		int nh = h + dx[i];
		int nw = w + dy[i];
		if(!in(nh, nw)) continue;
		if(A[nh][nw] == 'x') continue;
		if(seen[nh][nw])continue;
		cnt++;
		dfs(nh, nw);
	}
}
int main() {
	rep(i,H)cin>>A[i];
	int cnt_ans = 0;
	rep(i,H)rep(j,W){
		if(A[i][j] == 'o'){
			cnt_ans++;
		}
	}
	string ans = "NO";
	for (int i = 0; i < H; ++i){
		for (int j = 0; j < W; ++j){
			rep(k,H)rep(l,W){
				seen[k][l] = false;
			}
			if(A[i][j] == 'x'){
				cnt = 0;
				dfs(i,j);
/*				cerr<<cnt<<" "<<cnt_ans<<endl;
*/				if(cnt_ans == cnt){
					ans = "YES";
				}
			}
		}
	}
	cout<<ans<<endl;
}