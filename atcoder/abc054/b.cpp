#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)

int main() {
	int N,M;
	cin>>N>>M;
	vector<string> A(N),B(M);
	rep(i,N)cin>>A[i];
	rep(j,M)cin>>B[j];
	string ans = "No";
	rep(i,N)rep(j,N){
		int cnt = 0;
		rep(dx,M)rep(dy,M){
			int nx = i+dx,ny=j+dy;
			if(nx>=0&&nx<N&&ny>=0&&ny<N)
			if(A[nx][ny]==B[dx][dy])cnt++;
		}
		if(cnt == M*M)ans = "Yes";
	}
	cout<<ans<<endl;
}
