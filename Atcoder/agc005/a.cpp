#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)

int main() {
	string S;
	cin>>S;
	int N =S.size();
	int cnts = 0;
	rep(i,N){
		if(S[i]=='T'){
			if(cnts>0)cnts--;
		}
		else {
			cnts++;
		}
	}
	cout<<cnts*2<<endl;
}