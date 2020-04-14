#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()		//sort(all(vi S)) sort(all(string S))
//#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
//#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }

//using P = pair<int, int>;		//P.first, P.second
typedef long long ll;
typedef vector<int> vi;
typedef set<int> seti;
typedef vector<string> vs;

const int MOD = 1e9+7;
const int INF = 1e9;


/*binary_search(vc.begin(), vc.end(),X)
or
binary_search(all(vector),X)
で、ソート済み配列に対してXが存在するか返す。
使用例
if((binary_search(all(S), a))ans++;
*/


int main() {
	int N;
	cin>>N;
	vector<int> S(N);
	rep(i,N)cin>>S[i];
	int q;cin>>q;
	vector<int> T(q);
	rep(i,q)cin>>T[i];
	int ans = 0;
	rep(i,q){
		if(binary_search(all(S),T[i])){
			ans++;
		}
	}
	cout<<ans<<endl;
}