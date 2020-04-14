#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define all(a) (a).begin(),(a).end()

typedef long long ll;
typedef vector<int> vi;
typedef set<int> seti;
typedef vector<string> vs;

const int MOD = 1e9 + 7;
const int inf = 1e8;

int main() {
	int N,pmax = 0,sump= 0;
	cin>>N;
	vector<int> p(N);
	rep(i,N){
		cin>>p[i];
		pmax = max(pmax,p[i]);
		sump +=p[i];
	}

	int ans= sump-pmax/2;
	cout<<ans<<endl;
}