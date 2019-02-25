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
	string s,t;
	cin>>s>>t;
	int ans=2*N;
	rep(i,N){
		if(s.substr(i,N-i)==t.substr(0,N-i)){
			ans-=N-i;
			break;
		}
	}
	cout<<ans<<endl;
}