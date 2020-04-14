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
	vector<int> a(N);
	int sum = 0;
	rep(i,N){
		cin>>a[i];
		sum+=a[i];
	}
	vector<int> ans = {1};
	int cnt = a[0];
	rep1(i,N){
/*		cerr<<a[0]<< " "<<a[i]<<endl;
*/		if(a[0] >= 2 * a[i]){
			cnt += a[i];
			ans.push_back(i+1);
		}
	}
	if(2 * cnt > sum){
		cout<<ans.size()<<endl;
		rep(i,ans.size()){
			cout<<ans[i];
			if(i == ans.size()-1){
				cout<<endl;
			}else{
				cout<<" ";
			}
		}
	}
	else{
		cout<<0<<endl;
	}
}