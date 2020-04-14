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
	int N,M;
	cin>>N>>M;
	vector<P> v(M);
	vector<int> BoxN(N,1);
	vector<bool> InRed(N,false);
	InRed[0] = true;
	rep(i,M){
		int x,y;
		cin>>x>>y;
		x--;y--;
		if(InRed[x]){
			if(BoxN[x]==1){
				InRed[x] = false;
			}
			InRed[y] = true;
		}
		BoxN[x]--;
		BoxN[y]++;
	}
	int ans = 0;
	rep(i,N){
		if(InRed[i]){
			ans++;
		}
	}
	cout<<ans<<endl;
}