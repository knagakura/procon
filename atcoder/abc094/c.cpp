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
	vector<int> X(N);
	vector<int> Y(N);
	rep(i,N){
		cin>>X[i];
		Y[i]=X[i];
	}
	sort(all(Y));
	int ans = 0;
	rep(i,N){
		if(X[i]<=Y[N/2-1])ans = Y[N/2];
		else ans = Y[N/2-1];
		cout<<ans<<endl;
	}
}