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
	vector<int> L(N),M(N),R(N);
	rep(i,N)cin>>L[i];
	rep(i,N)cin>>M[i];
	rep(i,N)cin>>R[i];
	//左と右はソートしてOK
	sort(all(L));
	sort(all(R),greater<int>());
	//真ん中の累積和
	vector<int> Lsum(N+1),Msum(N+1),Rsum(N+1);
	Lsum[0] = Msum[0] = Rsum[0] = 0;
	rep(i,N){
		Lsum[i+1] = Lsum[i] + L[i];
		Msum[i+1] = Msum[i] + M[i];
		Rsum[i+1] = Rsum[i] + R[i];
	}
	print(L);print(M);print(R);
	print(Lsum);print(Msum);print(Rsum);

	ll ansL = 0;
	ll ansR = 10*INF;

	//左右は独立なので、左の最大化と右に最小化を別で行うが、
	//左右が重なって、Nを超える場合は考えてはならないので、そこに注意
	//境界を決めて、その時の最大化、最小化を別で行うことにすれば計算量改善

	//左にi個押し付けるとき
	rep(i,N+1){
	}
	cout<<ans<<endl;
}