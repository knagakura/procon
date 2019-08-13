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
	int N = S.size();
	int rcnt = 0;
	int lcnt = 0;
	vector<pair<int,P>> v;
	//rとlの境界線
	int x = 0;
	rep(i,N){
		if(S[i] == 'R'){
			rcnt++;
		}
		else{
			lcnt++;
		}
		if(i == N-1){
			v.push_back({x,{rcnt,lcnt}});
			continue;
		}
		if(S[i] == 'R'&&S[i+1] == 'L'){
			x = i;
		}
		if(S[i] == 'L'&&S[i+1] == 'R'){
			v.push_back({x,{rcnt,lcnt}});
			rcnt = 0;
			lcnt = 0;
		}
	}
	//
/*	rep(i,v.size()){
		if(i == 0)cerr<<"[";
		cerr<<"{"<<v[i].first<<", {"<<v[i].second.first<<", "<<v[i].second.second<<"}}, ";
	}
	cerr<<"]"<<endl;
	//*/
	vector<ll> ans(N);
	rep(i,v.size()){
		x = v[i].first;
		rcnt = v[i].second.first;
		lcnt = v[i].second.second;
		if((rcnt + lcnt)%2 == 0){
			ans[x] = ans[x+1] = (rcnt+lcnt)/2;
		}
		else{
			int longcnt = max(rcnt,lcnt);
			int large = (lcnt+rcnt)/2 + 1;
			int small = lcnt + rcnt - large;
			if(longcnt%2 == 0){
				if(rcnt > lcnt){
					ans[x] = small;
					ans[x+1] = large;
				}
				else{
					ans[x] = large;
					ans[x+1] = small;
				}
			}
			else{
				if(rcnt > lcnt){
					ans[x] = large;
					ans[x+1] = small;
				}
				else{
					ans[x] = small;
					ans[x+1] = large;
				}
			}
		}
	}
	rep(i,N){
		cout<<ans[i];
		if(i == N-1)cout<<endl;
		else cout<<" ";
	}
}