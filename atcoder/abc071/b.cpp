#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)

int main() {
	string S;
	cin>>S;
	int N=S.size();
	string ans = "None";
	vector<bool> f(26);
	rep(i,26){
		f[i]=false;
		char c = 'a'+i;
		rep(j,N){
			if(S[j] == c)
				f[i]=true;
		}
	}
	rep(i,26){
		if(!(f[i])){
			ans='a'+i;
			break;
		}
	}
	cout<<ans<<endl;
}