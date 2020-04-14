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

map <ll,ll> mpd,mpt;
int main() {
	int N,M;
	cin>>N;vector<int> D(N);
	rep(i,N)cin>>D[i];
	cin>>M;vector<int> T(M);
	rep(i,M)cin>>T[i];

	rep(i,N)mpd[D[i]]++;
	rep(i,M)mpt[T[i]]++;
	string ans = "YES";
	rep(i,M){
		if(mpt[T[i]]>mpd[T[i]]){
			ans = "NO";
			break;
		}
	}
	cout<<ans<<endl;
}