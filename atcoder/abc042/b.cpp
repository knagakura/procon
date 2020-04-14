#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()	

int main() {
	int N,L;
	cin>>N>>L;
	vector<string> S(N);
	rep(i,N)cin>>S[i];
	sort(all(S));
	rep(i,N)cout<<S[i];
	cout<<endl;
}