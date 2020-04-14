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
	string S;
	cin>>S;
	string T = "";
	rep(i,N-1){
		if(S[i] == 'v' && S[i] == S[i+1]){
			T.push_back('w');
		}
		else if(S[i] == 'o'){
			T.push_back('o');
		}
		else{
			T.push_back('x');
		}
	}
	cerr<<T<<endl;
	int ans;
	
	cout<<ans<<endl;
}