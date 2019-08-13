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

int dist[108][108];
int main() {
	int N,M;
	cin>>N>>M;
	rep(i,N)rep(j,N){
		if(i == j)dist[i][j] = 0;
		else dist[i][j] = INF;
	}
	vector<int> a(M),b(M),c(M);
	rep(i,M){
		cin>>a[i]>>b[i]>>c[i];
		a[i]--;b[i]--;
		dist[a[i]][b[i]] = dist[b[i]][a[i]] = c[i];
	}
	/*
	多点間最短距離を求めるO(V^3)のアルゴリズム。
	距離行列dist[MAX_N][MAX_N]が必要。
	※0-indexにしておく。
	*/
	rep(k,N)rep(i,N)rep(j,N){
			dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
	}
	int ans = M;
	for (int i = 0; i < M; ++i){
		bool shortest = false;
		for (int j = 0; j < N; ++j){
			if(dist[j][a[i]] + c[i] ==dist[j][b[i]]){
				shortest = true;
			}
		}
		if(shortest){
			ans--;
		}
	}
	cout<<ans<<endl;
}