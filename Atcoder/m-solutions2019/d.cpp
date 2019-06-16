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

int main() {
	int N;
	cin>>N;
	vector<vector<int>> G(10005);
	rep(i,N-1){
		int a,b;
		cin>>a>>b;
		a--;b--;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	vector<int> c(N);
	rep(i,N){
		cin>>c[i];
	}
	sort(all(c));
	queue<int> q;
	vector<int> ansv(N),used(N,0);
	ansv[0] = c[N-1];
	used[0] = 1;
	print(c);
	print(ansv);
	print(used);
	q.push(0);
	int ans = 0;
	int now = N-2;
	while(!q.empty()||now>=0){
		int v = q.front();q.pop();
		cerr<<v;
		print(G[v]);
		for(int u :G[v]){
			if(used[u])continue;
			//cerr<<"		"<<u<<endl;
			q.push(u);
			used[u] = 1;
			ans += c[now];
			ansv[u] = c[now];
			now--;
		}
	}
	cout<<ans<<endl;
	rep(i,N){
		if(i == N-1)cout<<ansv[i]<<endl;
		else cout<<ansv[i]<<" ";
	}
}