#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)

int N,M;
int a[100],b[100];

bool graph[100][100];
bool visited[100];

int ans = 0;
int cnt = 0;

void dfs(int v){
	cnt++;
	if(cnt == N)ans++;
	visited[v] = true;
	rep(v2,N){
		if(graph[v][v2] == false) return;
		if(visited[v2] == true) return;
		dfs(v2);
	}
}
int main() {
	cin>>N>>M;
	rep(i,M){
		cin>>a[i]>>b[i];
		a[i]--;b[i]--;
		graph[a[i]][b[i]] = graph[b[i]][a[i]] = true;
	}
	rep(i,N)visited[i] = false;

	dfs(0);
	cout<<ans<<endl;
}









