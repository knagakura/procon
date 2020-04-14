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
	vector<int> W(N);
	int sum_W = 0;
	rep(i,N){
		cin>>W[i];
		sum_W +=W[i];
	}
	int ans = sum_W;
	int w1 = 0;
	int w2 = sum_W;
	rep(i,N){
		w1 += W[i];
		w2 -= W[i];
		cerr<<w1<<" "<<w2<<endl;
		ans = min(ans,abs(w2-w1));
	}
	
	cout<<ans<<endl;
}