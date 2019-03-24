#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()		//sort(all(vi S)) sort(all(string S))

typedef long long ll;
typedef vector<int> vi;
typedef set<int> seti;
typedef vector<string> vs;

const int MOD = 1e9+7;
const int INF = 1e9;

int main() {
	int N;
	cin>>N;
	string S,T,s;
	int n,m;
	vector<vector<int>> ans(N);
	rep(i,N){
		cin>>S>>T;
		n = S.size();
		m = T.size();
		for (int j = 0; j + m - 1 < n; ++j){
			s = S.substr(j,m);
			if(s == T){
				ans[i].push_back(j+1);
			}
		}
	}
	rep(i,N){
		int M = ans[i].size();
		rep(j,M){
			if(j == M-1)cout<<ans[i][j]<<endl;
			else cout<<ans[i][j]<<' ';
		}
	}
}