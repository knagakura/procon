#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_.first<<", "<<_.second<<", "; cerr<<"]"<<endl; }

using P = pair<int, int>;		//P.first, P.second
typedef long long ll;

const int MOD = 1e9+7;
const int INF = 1e9;

int main() {
	string S;
	cin>>S;
	int N = S.size();
	int g = 0, p = 0;
	vector<P> V(N+1);
	V[0] = {0,0};
/*	rep(i,N){
		if(S[i] == 'g')g++;
		else p++;
		V[i+1] = {g,p};
	}*/
	int ans = 0;
	string Sn = "";
	rep(i,N){
		g = V[i].first;
		p = V[i].second;
		if(S[i] == 'g'){
			if(g>p){
				//cout<<'p';
				p++;
				ans++;
			}
			else{
				//cout<<'g';
				g++;
			}
		}
		else{
			if(g>p){
				//cout<<'p';
				p++;
			}
			else {
				//cout<<'g';
				g++;
				ans--;
			}
		}
		V[i+1] = {g,p};
	}
	print(V);

	cout<<ans<<endl;
}