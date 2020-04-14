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
	vector<int> h(N);
	int ans = 0;
	rep(i,N){
		cin>>h[i];
	}
	rep(i,N){
		if(i == N-1)ans+=h[i];
		else{
			if(h[i]>h[i+1])ans+=h[i]-h[i+1];
		}		
	}
	cout<<ans<<endl;
}