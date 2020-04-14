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
	int N,X,Y;
	cin>>N>>X>>Y;
	vector<int> A(N);
	
	rep(i,N){
		cin>>A[i];
	}
	sort(all(A),greater<int>());;
	rep(i,N){
		if(i%2 == 0)X+=A[i];
		else Y+=A[i];
	}
	string ans = "Takahashi";
	if(Y>X)ans ="Aoki";
	else if(X==Y) ans ="Draw";
	cout<<ans<<endl;
}