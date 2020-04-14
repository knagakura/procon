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
	ll A,B,C;
	cin>>A>>B>>C;
	ll AA,BB,CC;
	ll ans = 0;
	ll A1 = A,B1 = B,C1 = C;
	while(A%2 == 0 && B%2 == 0 && C%2 == 0){
		AA = A/2;
		BB = B/2;
		CC = C/2;
		A = BB+CC;
		B = CC+AA;
		C = AA+BB;
		if(A==A1&&B==B1&&C==C1){
			cout<<-1<<endl;
			return 0;
		}
		ans++;
	}
	cout<<ans<<endl;
}