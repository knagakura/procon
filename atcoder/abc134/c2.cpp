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
	vector<int> a_pre(N);
	rep(i,N){
		cin>>a[i];
		a_pre[i] = a[i];
	}
	sort(all(a));
	/*print(a);
	print(a_pre);*/
	rep(i,N){
		if(a_pre[i] == a[N-1]){
			cout<<a[N-2]<<endl;
		}
		else{
			cout<<a[N-1]<<endl;
		}
	}
}