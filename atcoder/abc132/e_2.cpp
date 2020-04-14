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

int dist[100005][3];
int main() {
	int N,M;
	cin>>N>>M;
	vector<vector<int>> to(N);
	rep(i,M){
		int a,b;
		cin>>a>>b;
		a--;b--;
		to[a].push_back(b);
	}
	int sv,tv;
	cin>>sv>>tv;
	sv--;tv--;
	rep(i,N)rep(j,3) dist[i][j] = INF;
	queue<P> q;
	q.push({sv,0});
	dist[sv][0] = 0;
	while(!q.empty()){
		int v = q.front().first;
		int l = q.front().second;
		q.pop();
		for(int u: to[v]){
			int nl = (l+1)%3;
			if(dist[u][nl]!=INF)continue;
			dist[u][nl] = dist[v][l] + 1;
			q.push({u,nl});
		}
	}
	int ans = dist[tv][0];
	if(ans == INF)ans = -1;
	else ans /= 3;
	cout<<ans<<endl;
}