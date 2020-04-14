#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
typedef long long ll;

int main() {
	string S;	
	cin>>S;
	int N = S.size();
	string T;
	rep(i,N){
		if(S[i] == 'A'){
			T.push_back('A');
		}
		else if(S[i] == 'B'){
			if(i+1 < N && S[i+1] == 'C'){
				T.push_back('D');
				i++;
			}
			else{
				T.push_back('X');
			}
		}
		else{
			T.push_back('X');
		}
	}
	cerr<<T<<endl;
	ll ans = 0;
	int a = 0;
	int M = T.size();
	rep(i,M){
		if(T[i] == 'A'){
			a++;
		}
		else if(T[i] == 'D'){
			ans += a;
		}
		else{
			a = 0;
		}
	}
	cout<<ans<<endl;
}