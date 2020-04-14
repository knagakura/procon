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
	std::map<ll, ll> map;
	rep(i,N){
		int a;
		cin>>a;
		if(a % 2 == 1){
			map[1]++;
		}
		else{
			if(a % 4 == 0){
				map[4]++;
			}else{
				map[2]++;
			}
		}
	}
	string ans = "Yes";
	if(N % 2== 0){
		if(map[1]>map[4]){
			ans = "No";
		}
	}else{
		if(map[1] == (N+1)/2){
			if(map[4]<map[1]-1){
				ans = "No";
			}
		}
		else if(map[1]<(N+1)/2){
			if(map[4]<map[1]){
				ans = "No";
			}
		}
		else{
			ans = "No";
		}
	}
	cout<<ans<<endl;
}