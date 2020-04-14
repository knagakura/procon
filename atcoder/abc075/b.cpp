#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)

int main() {
	int H,W;
	cin>>H>>W;
	vector<string> S(H);
	rep(i,H){
		cin>>S[i];
		cout<<S[i]<<endl;
	}
	rep(i,H)rep(j,W){
		if(S[i][j] == '.'){
			S[i][j]='0';
			for (int dx = -1; dx <= 1; ++dx){
				for (int dy = -1; dy <= 1; ++dy){
					int nx = i+dx,ny = j+dy;
					if(0<=nx&&nx<H&&0<=ny&&ny<W){
						if(S[nx][ny]=='#')S[i][j]++;
					}
					
				}
				
			}
		}
	}
rep(i,H)cout<<S[i]<<endl;
}