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
	rep(i,N)cin>>a[i];
	// 左からiまで見た時のmaxla, 右から
	vector<int> maxla(N,0),maxra(N,0);
	maxla[0] = a[0];
	maxra[N-1] = a[N-1];
	rep1(i,N){
		maxla[i] = max(maxla[i-1], a[i]);
	}
	for (int i = N-2; i >= 0; --i){
		maxra[i] = max(maxra[i+1], a[i]);
	}
	//print(maxla);print(maxra);
	rep(i,N){
		if(i == 0){
			cout<<maxra[1]<<endl;
		}
		else if(i == N-1){
			cout<<maxla[N-1]<<endl;
		}
		else{
			cout<<max(maxla[i-1], maxra[i+1])<<endl;;
		}
	}
}