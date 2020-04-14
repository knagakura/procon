#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()		//sort(all(vi S)) sort(all(string S))
#define push_back pb

using P = pair<int, int>;		//P.first, P.second
typedef long long ll;
typedef vector<int> vi;
typedef set<int> seti;
typedef vector<string> vs;

const int MOD = 1e9+7;
const int INF = 1e9;

int main() {
	int N;
	cin>>N;
	vector<int> V(N);
	vector<int> C(N);
	rep(i,N){
		cin>>V[i];
	}
	rep(i,N)cin>>C[i];
	int ans = 0;
	rep(i,N){
		if(V[i]-C[i]>0)ans+=V[i]-C[i];
	}
	cout<<ans<<endl;
}