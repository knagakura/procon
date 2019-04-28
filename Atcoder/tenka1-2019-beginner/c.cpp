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
	string S;
	cin>>N>>S;
	//iまで見たときのBの個数、Wの個数
	vector<int> B(N),W(N);
	int bcnt = 0, wcnt = 0;
	rep(i,N){
		if(S[i]=='.'){
			wcnt++;
		}
		else{
			bcnt++;
		}
		W[i] = wcnt;
		B[i] = bcnt;
	}
	int ans = INF;
	//iまで全て.にして、それ以降全て#にするのにかかる工程数
	//print(W);print(B);
	//cout<<W.size()<<B.size()<<endl;
	rep(i,N){
		int n = 0;
		n += B[i];
		n += wcnt - W[i];
		ans = min(ans,n);
	}
	ans = min(ans,N-bcnt);
	ans = min(ans,N-wcnt);
	if(bcnt == N)ans = 0;
	if(wcnt == N)ans = 0;

	cout<<ans<<endl;
}