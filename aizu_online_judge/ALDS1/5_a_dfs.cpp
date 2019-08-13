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

int N;
int m;
bool dfs(int now, const vector<int> &v, int sum){
	if(now == N){
		return sum == 0;
	}
	if(dfs(now+1, v, sum-v[now]))return true;
	if(dfs(now+1, v, sum))return true;
	return false;
}

int main() {
	cin>>N;
	vector<int> A(N);
	rep(i,N)cin>>A[i];
	int q;cin>>q;
	rep(i,q){
		cin>>m;
		if(dfs(0, A, m)){
			cout<<"yes"<<endl;
		}
		else{
			cout<<"no"<<endl;
		}
	}
	return 0;
}