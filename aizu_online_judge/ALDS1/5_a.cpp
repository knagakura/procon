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
int A[25];
int N,q;

bool dfs(int i, int sum, int M){
	cerr<<i<<": "<<sum<<endl;
	if(i == N){
		return sum == M;
	}
	if(dfs(i+1,sum+A[i],M))return true;
	if(dfs(i+1, sum, M)) return true;
	return false;
}

int main() {
	cin>>N;
	rep(i,N)cin>>A[i];
	cin>>q;
	rep(i,q){
		int M;
		cin>>M;
		if(dfs(0, 0, M)){
			cout<<"yes"<<endl;
		}
		else{
			cout<<"no"<<endl;
		}
	}
}