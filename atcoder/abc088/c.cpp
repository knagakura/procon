#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()		//sort(all(vi S)) sort(all(string S))
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }

using P = pair<int, int>;		//P.first, P.second
typedef long long ll;
typedef vector<int> vi;
typedef set<int> seti;
typedef vector<string> vs;

const int MOD = 1e9+7;
const int INF = 1e9;

int main() {
	int c[3][3];
	rep(i,3)rep(j,3)cin>>c[i][j];
	int d1 = c[0][1]-c[0][0];
	int d2 = c[0][2]-c[0][0];
	string ans = "Yes";
	rep1(i,3)rep(j,3){
		if(c[i][1]-c[i][0] == d1&&c[i][2]-c[i][0]==d2){
			continue;
		}
		else{
			ans = "No";
		}
	}
	cout<<ans<<endl;
}