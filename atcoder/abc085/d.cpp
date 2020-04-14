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
	int N,H;
	cin>>N>>H;
	vector<P> ab;
	rep(i,N){
		int a,b;
		cin>>a>>b;
		ab.push_back({a,1});
		ab.push_back({b,0});
	}
	ll ans = 0;
	sort(all(ab));
	rep(i,2*N){
		cerr<<H<<endl;
		int x = ab[2*N-1-i].first;
		int y = ab[2*N-1-i].second;
		cerr<<x<<" "<<y<<endl;
		if(y){
			if(H%x ==0)ans+=H/x;
			else{
				ans+=H/x+1;
			}
			break;
		}
		H -= x;
		ans++;
		if(H<=0)break;
	}
	printpair(ab);
	cout<<ans<<endl;
}