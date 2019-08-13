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
	int N,b;
	cin>>N;
	cin>>b;
	vector<int> a(N-1);
	int sum = b;
	rep(i,N-1){
		cin>>a[i];
		sum += a[i];
	}
	sort(all(a));
	print(a);
	vector<int> ans;
	ans.push_back(1);
	int cnt = b;
	rep(i,N-1){
		cerr<<cnt+a[i]<<endl;
		if(b >(cnt + a[i])/2){
			cnt += a[i];
			ans.push_back(i+2);
		}
	}
	print(ans);
	if(cnt > sum/2){
		cout<<ans.size()<<endl;
		for (int i = 0; i < ans.size(); ++i){
			cout<<ans[i];
			if(i == ans.size()-1)cout<<endl;
			else{
				cout<<" ";
			}
		}
	}
	else{
		cout<<0<<endl;
	}
}