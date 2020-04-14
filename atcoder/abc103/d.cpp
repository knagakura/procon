#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)

using P = pair<int, int>;		//P.first, P.second
typedef long long ll;

const int MOD = 1e9+7;
const int INF = 1e9;

int main() {
	int N,M;
	cin>>N>>M;
	vector<P> v;
	rep(i,M){
		int a,b;
		cin>>a>>b;
		v.push_back({a,b});
	}
	sort(v.rbegin(), v.rend());
	printpair(v);
	int ans = 0;
	int r = INF;
	rep(i,M){
		if(v[i].second<=r){
			ans++;
			r = v[i].first;
		}
	}
	cout<<ans<<endl;
}