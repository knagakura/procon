#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()		//sort(all(vi S)) sort(all(string S))
#define push_back pb
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<", "<<_.second<<"}"<<", "; cerr<<"]"<<endl; }

using P = pair<int, char>;		//P.first, P.second
typedef long long ll;
typedef vector<int> vi;
typedef set<int> seti;
typedef vector<string> vs;

const int MOD = 1e9+7;
const int INF = 1e9;

int main() {
	int T,N,M;
	cin>>T>>N;
	vector<int> A(N);
	rep(i,N)cin>>A[i];
	cin>>M;
	vector<int> B(M);
	rep(i,M)cin>>B[i];
	int ans;
	vector<P> AB(N+M);
	rep(i,N){
		AB[i] = {A[i],'A'};
	}
	rep(i,M){
		AB[i+N] = {B[i],'B'};
	}
	sort(all(AB));
	print(AB);
	vector<int> AA = {};
	rep(i,N+M){
		if(AB[i].second == 'A'){
			
		}
	}
	cout<<ans<<endl;
}