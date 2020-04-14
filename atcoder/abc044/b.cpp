#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()

int main() {
	string w;
	cin>>w;
	sort(all(w));
	int N=w.size();
	string ans="No";
	int cnt=0;
	if(N%2==0){
		for (int i = 0; 2*i+1 < N; ++i){
		if(w[2*i]==w[2*i+1])cnt+=2;
		}
		if(cnt==N)ans="Yes";
	}
	cout<<ans<<endl;
}