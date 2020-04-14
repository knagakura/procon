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
int N,Q;
string S;
vector<int> l(100010),r(100010);
vector<int> ACl,ACr;
int main() {
	cin>>N>>Q>>S;
	rep(i,Q){
		cin>>l[i]>>r[i];
		l[i]--;r[i]-=2;
	}
	int cnt = 0;
	rep(i,N-1){
		if(S.substr(i,2)=="AC"){
			ACl.push_back(i);
			cnt++;
		}
	}
	sort(all(ACl));
	rep(i,Q){
		auto iter_lower_l = lower_bound(all(ACl), l[i]);
		auto iter_upper_r = upper_bound(all(ACl), r[i]);
		ll idx_lower_l = distance(ACl.begin(), iter_lower_l);
		ll idx_upper_r = distance(ACl.begin(), iter_upper_r);
		int ans = idx_upper_r -idx_lower_l;
		cout<<ans<<endl;
	}
	//cout<<ans<<endl;
}