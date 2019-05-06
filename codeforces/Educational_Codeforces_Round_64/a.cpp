#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
typedef long long ll;
int main() {
	int N;
	cin>>N;
	vector<ll> v(N);
	rep(i,N)cin>>v[i];
	bool inf = false;
	ll ans = 0;
	ll a,b,c;
	for (int i = 0; i < N-1; ++i){
		a = v[i];b = v[i+1];
		if(a ==1){
			if(b == 2)ans+=3;
			if(b == 3)ans+=4;
		}
		if(a == 2){
			if(b == 1)ans+=3;
			if(b == 3)inf = true;
		}
		if(a == 3){
			if(b == 1)ans+=4;
			if(b == 2)inf = true;
		}
	 }
	for (int i = 0; i < N-2; ++i){
		a = v[i];b = v[i+1];c = v[i+2];
		if(a == 3&&b == 1&&c == 2)ans--;
	}
	if(inf){
		cout<<"Infinite"<<endl;
	}
	else{
		cout<<"Finite"<<endl;
		cout<<ans<<endl;
	}
	
}