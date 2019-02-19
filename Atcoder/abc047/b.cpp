#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)

int main() {
	int X,Y,N;
	cin>>X>>Y>>N;

	int graph[X][Y];
	rep(i,X)rep(j,Y)graph[i][j]=0;

	vector<int> x(N),y(N),a(N);
	rep(k,N){
		cin>>x[k]>>y[k]>>a[k];
		if(a[k]==1){
			rep(i,X)rep(j,Y){
				if(i<x[k])graph[i][j]=1;
			}
		}
		if(a[k]==2){
			rep(i,X)rep(j,Y){
				if(i>=x[k])graph[i][j]=1;
			}
		}
		if(a[k]==3){
			rep(i,X)rep(j,Y){
				if(j<y[k])graph[i][j]=1;

			}
		}
		if(a[k]==4){
			rep(i,X)rep(j,Y){
				if(j>=y[k])graph[i][j]=1;
			}
		}
	}

	int ans=0;
	rep(i,X)rep(j,Y){
		ans+=graph[i][j];
	}
	cout<<X*Y-ans<<endl;
}