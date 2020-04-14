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

int main() {
	string S;
	cin>>S;
	string ans = "NA";
	int X = int(S[0]-'0')*10 + int(S[1]-'0');
	int Y = int(S[2]-'0')*10 + int(S[3]-'0');
	if(0<X&&X<=12){
		if(0<Y&&Y<=12){
			ans = "AMBIGUOUS";
		}
		else{
			ans = "MMYY";;
		}
	}
	else if(X==0){
		if(0<Y&&Y<=12){
			ans = "YYMM";
		}
	}
	else{
		if(0<Y&&Y<=12){
			ans = "YYMM";
		}
		else{
			ans = "NA";
		}
	}
	cout<<ans<<endl;
}