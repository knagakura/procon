#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()		//sort(all(vi S)) sort(all(string S))
#define push_back pb
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }

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
	vector<string> s(N);
	rep(i,N)cin>>s[i];
	ll ans = 0;
	int len = 0;
	//並べる前にある文字列を数え上げ（O(N*10))
	for (int i = 0; i < N; ++i){
		len = s[i].size();
		for (int j = 0; j+1 < len ; ++j){
			if(s[i][j] == 'A' && s[i][j+1] == 'B'){
				ans++;
			}
		}
	}
	ll c = 0;
	ll a = 0;
	ll b = 0;
	for (int i = 0; i < N; ++i){
		len = s[i].size();
		if(s[i][len-1] == 'A'&&s[i][0] =='B'){
			c++;
		}
		else if(s[i][len-1] == 'A'){
			a++;
		}
		else if(s[i][0] == 'B'){
			b++;
		}
	}
	if(c>0){
		ans += c-1;
		if(a>0){
			ans += 1;
			a--;
		}
		if(b>0){
			ans += 1;
			b--;
		}
		ans += min(a,b);
	}
	else{
		ans += min(a,b);
	}
	cout<<ans<<endl;
}