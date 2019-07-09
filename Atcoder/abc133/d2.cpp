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
	vector<ll> A(N);
	ll summ = 0;
	rep(i,N){
		cin>>A[i];
		summ += A[i];
	}
	vector<ll> Mt(N);
	for (int i = 0; i < N; i++){
		if(i%2 == 0)continue;
		summ-=2*A[i];
	}
	Mt[0] = summ;
	rep(i,N-1){
		Mt[i+1] = 2*A[i] - Mt[i];
	}
	rep(i,N){
		if(i==N-1){
			cout<<Mt[i]<<endl;
			return 0;
		}
		cout<<Mt[i]<<" ";
	}
}