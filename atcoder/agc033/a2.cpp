#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()		//sort(all(vi S)) sort(all(string S))
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }

using P = pair<int, int>;		//P.first, P.second
typedef long long ll;
typedef vector<int> vi;
typedef set<int> seti;
typedef vector<string> vs;

const int MOD = 1e9+7;
const int INF = 1e9;
ll H,W;
vector<string> Sn(1005);

int main() {
	cin>>H>>W;
	vector<string> A(H);
	rep(i,H)cin>>A[i];
	int c = 0;
	rep(i,H)rep(j,W){
		if(A[i][j] == '.')c++;
	}
	if(c == 0){
		cout<<0<<endl;
		return 0;
	}
	int ans = 0;

	while(true){
		string s = "";
		rep(i,W)s+=".";
		rep(i,H){
		Sn[i] = s;
		}
		rep(i,H)rep(j,W){
			if(A[i][j] == '#'){
				Sn[i][j] = '#';
				if(0<=i-1)Sn[i-1][j] = '#';
				if(0<=j-1)Sn[i][j-1] = '#';
				if(i+1<H) Sn[i+1][j] = '#';
				if(j+1<W) Sn[i][j+1] = '#';
			}
		}
		ans++;
		c = 0;
		rep(i,H)rep(j,W){
			if(Sn[i][j] == '.'){
				c++;
			}
		}
		if(c == 0)break;
		A = Sn;
	}
	cout<<ans<<endl;
	return 0;
}