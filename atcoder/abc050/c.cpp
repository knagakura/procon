#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()		//sort(all(vi S)) sort(all(string S))
#define push_back pb
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }

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
	vector<int> A(N);
	rep(i,N)cin>>A[i];
	sort(all(A));
	vector<int> cnt(N);
	rep(i,N)cnt[A[i]]++;
	bool f = true;
	if(N%2 == 1){
		if(cnt[0] !=1)f = false;
		for (int i = 1; 2*i < N; ++i){
			if(cnt[2*i] !=2)f = false;
		}
	}
	else{
		for (int i = 0; 2*i+1 < N; ++i){
			if(cnt[2*i+1]!=2)f = false;
		}
	}
	int ans = 0;
	if(f){
	ans = 1;
	for (int i = 0; i < N/2; ++i){
				ans*=2;
				ans%=MOD;
			}		
	}
	print(cnt);
	cout<<ans<<endl;
}