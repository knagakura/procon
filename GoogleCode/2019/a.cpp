#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()		//sort(all(vi S)) sort(all(string S))

typedef long long ll;
typedef vector<int> vi;
typedef set<int> seti;
typedef vector<string> vs;

const int MOD = 1e9+7;
const int INF = 1e9;
int T;
int N;
int P;
int main() {
	cin>>T;
	rep1(t,T+1){
		cin>>N>>P;
		vector<int> S(N);
		rep(i,N)cin>>S[i];
		sort(all(S));

		ll sum = 0;
		//P個の最大値とそれらとの差の合計
		rep(i,P){
			sum+=abs(S[P-1]-S[i]);
		}
		vector<ll> ans;
		ans.push_back(sum);

		for (int i = 1; i+P-1 < N; ++i){
			int Smax_pre  = S[i+P-2];
			int Smax_post = S[i+P-1];
			int Smin_pre  = S[i-1];
			sum += (Smax_post - Smax_pre)*(P-1);
			sum -= (Smax_pre - Smin_pre);
			ans.push_back(sum);
			}
		ll ansmin = INF;
		rep(i,ans.size()){
			ansmin = min(ansmin, ans[i]);
		}
		cout<<"Case #"<<t<<": "<<ansmin<<endl;
	}
}