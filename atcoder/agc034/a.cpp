#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define all(a) (a).begin(),(a).end()

typedef long long ll;

int main() {
	ll N,A,B,C,D;
	cin>>N>>A>>B>>C>>D;
	A--;B--;C--;D--;
	string S;cin>>S;
	vector<int> a(N,0),b(N,0);
	a[A] = 1;
	b[B] = 1;
	rep(i,N){
		if(i+1<N)
		if(a[i]&&S[i+1] == '.'){
			a[i+1]++;
		}
		if(i+2<N)
		if(a[i]&&S[i+2] == '.'){
			a[i+2]++;
		}
		if(i+1<N)
		if(b[i]&&S[i+1] == '.'){
			b[i+1]++;
		}
		if(i+2<N)
		if(b[i]&&S[i+2] == '.'){
			b[i+2]++;
		}
	}
	bool can = false;
	for (int i = B-1; i+1 <= D; ++i){
		if(a[i]&&b[i+1]&&a[i+2]){
			can = true;
		}
	}
	string ans = "No";
	if(C<D){
		if(a[C]&&b[D])ans ="Yes";
	}
	else{
		if(a[C]&&b[D]&&can){
			ans = "Yes";
		}
	}
	cout<<ans<<endl;
}