#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()		//sort(all(vi S)) sort(all(string S))

typedef long long ll;
typedef vector<int> vi;
typedef set<int> seti;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;

const int MOD = 1e9+7;
const int INF = 1e9;

int main() {
	int N;
	cin>>N;
	vector<string> S(100);
	int v[100][100];
	rep(i,N){
		cin>>S[i];
		sort(all(S[i]));

		rep(j,S[i].size()){
			int k = S[i][j] - 'a';
			v[i][k]++;
		}
	}
	
	cout<<endl;
}