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
	int N;
	cin>>N;
	string S1,S2;
	cin>>S1>>S2;
	S1.push_back('1');S1.push_back('3');
	S2.push_back('2');S2.push_back('4');
	ll ans;
	int start;
	int joutai;
	if(S1[0] == S2[0]){
		ans = 3;
		start = 1;
		joutai = 1;
	}
	else{
		ans = 6;
		start = 2;
		joutai = 2;
	}
	for (int i = start; i <= N; ++i){
		if(S1[i] == S2[i]){
			if(joutai == 1){
				ans *= 2;
				ans %= MOD;
			}else{
				ans *= 1;
				ans %= MOD;
			}
			joutai = 1;
		}
		else if(S1[i] == S1[i+1]&&S2[i]==S2[i+1]){
			if(joutai == 1){
				ans *= 2;
				ans %= MOD;
			}else{
				ans *= 3;
				ans %= MOD;
			}
			i++;
			joutai = 2;
		}
		else{
			break;
		}
		ans %= MOD;
		/*cerr<<ans<<endl;
		cerr<<S1[i]<<endl;
*/	}
	ans %= MOD;
	cout<<ans<<endl;
}