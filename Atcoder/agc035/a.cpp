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
	vector<ll> a(N);
	rep(i,N)cin>>a[i];
	sort(all(a));
	std::map<ll, ll> map;
	rep(i,N){
		map[a[i]]++;
	}
	ll cnt = map.size();
	cerr<<cnt<<endl;
	if(N%3 != 0){
		if(map[0] == N){
			cout<<"Yes"<<endl;
		}
		else{
			cout<<"No"<<endl;
		}
		return 0;
	}
	string ans = "No";
	if(cnt == 3){
		ll res = 0;
		for(auto x: map){
			res ^= x.first;
			if(x.second != N/3){
				res = INF;
				break;
			}
		}
		if(res == 0)ans = "Yes";
	}
	else if(cnt == 2){
		if(map[0] == N/3)ans = "Yes";
	}
	else if(cnt == 1){
		if(map[0] == N)ans = "Yes";
	}
	cout<<ans<<endl;
}