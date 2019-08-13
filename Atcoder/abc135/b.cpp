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
	vector<int> p(N);
	rep(i,N){
		cin>>p[i];
	}
	vector<int> t(N);
	rep(i,N){
		t[i] = i+1;
	}
	string ans = "NO";
	rep(i,N)rep(j,N){
		vector<int> q(N);
		rep(k,N){
			if(k == i){
				q[k] = p[j];
			}
			else if(k == j){
				q[k] = p[i];
			}
			else{
				q[k] = p[k];
			}
		}
		if(q == t){
			ans = "YES";
			i = j = N;
		}
	}
	cout<<ans<<endl;
}