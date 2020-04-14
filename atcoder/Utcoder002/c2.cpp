#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()		//sort(all(vi S)) sort(all(string S))
#define push_back pb
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }

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
	vector<bool> Bf(M);
	rep(i,M)cin>>B[i];
	string ans = "yes";
	if(N<M){
		cout<<"no"<<endl;
		return 0;
	}
	for (int i = 0; i < N; ++i){
		bool f = true;
		if(f)
		for (int j = 0; j < M; ++j){
			if(0<=B[j]-A[i]&&B[j]-A[i]<=T&&Bf[j] == false){
				Bf[j] = true;
				break;
				f = false;
			}
		}	
	}
	print(Bf);
	rep(i,M)if(!(Bf[i]))ans = "no";
	cout<<ans<<endl;
}