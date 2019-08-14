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
	ll x,y;
	cin>>x>>y;
	cerr<<x*y<<endl;
	int ans;
	if(x == 0){
		if(y > 0){
			ans = y;
		}
		else{
			ans = abs(y) + 1;
		}
	}
	else if(y == 0){
		if(x > 0){
			ans = abs(x) + 1;
		}
		else{
			ans = abs(x);
		}
	}
	else if(x*y<0){
		ans = abs(abs(x)-abs(y))+1;
	}
	else if(x*y>0){
		if(y<x){
			ans = abs(abs(x)-abs(y)) + 2;
		}
		else{
			ans = abs(abs(x)-abs(y));
		}
	}
	cout<<ans<<endl;
}