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
const int INF = 1e9

//bit全探索
int main() {
	string S;
	cin>>S;
	// 全探索 --- bit は0 ~ 1000の手前まで動くと思う
	for (int bit = 0; bit < (1<<3); ++bit){
		int res = S[0] - '0';
		string ans = "";
		ans.push_back(S[0]);
		/* bit で表される集合の処理を書く */
		for (int i = 0; i < 3; ++i){
			if(bit & 1<<i){
				res += S[i+1] - '0';
				ans.push_back('+');
				ans.push_back(S[i+1]);
			}
			else{
				res -= S[i+1] - '0';
				ans.push_back('-');
				ans.push_back(S[i+1]);
			}
		}
		if(res == 7){
			cout<<ans<<"=7"<<endl;
			break;
		}
	}	
}