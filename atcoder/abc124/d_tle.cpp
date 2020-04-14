#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()		//sort(all(vi S)) sort(all(string S))

typedef long long ll;
typedef vector<int> vi;
typedef set<int> seti;
typedef vector<string> vs;

const int MOD = 1e9+7;
const int INF = 1e9;

//0と1の境界があるかないか
vector<bool> f(100005);

int ans;
int main() {
	int N,K;cin>>N>>K;
	string S;cin>>S;
	if(N == 1){cout<<1<<endl;return 0;}
	vector<pair<int,ll>> v;
	ll cnt = 1;
	rep(i,N){
		if(S[i]!=S[i+1]){
			v.push_back({S[i]-'0',cnt});
			cnt = 1;
		}
		else cnt++;
	}
	ans = 0;
	rep(i,v.size()){
		if(v[i].first == 1)
		ans = max(ans,int(v[i].second));
	}
	//cout<<ans<<endl;
	//rep(i,v.size())cout<<v[i].first<<" "<<v[i].second<<endl;
	int M = v.size();
	ans = 0;
	rep(i,M){
		int Count = 1;
		int H = 0;
		for (int j = i; Count <= K; ++j){
			if(v[j].first == 0){
				Count++;
			}
			H+=v[j].second;
			if(Count == K+1)H+=v[j+1].second;
		}
		ans = max(ans,H);
	}
	cout<<ans<<endl;
}