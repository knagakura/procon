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

int main() {
	string S;
	cin>>S;
	int N =S.size();
	int ans1 = 0;
	rep(i,N){
		if(i%2 == 0){
			if(S[i] == '1')ans1++;
		}
		else{
			if(S[i] == '0')ans1++;
		}
	}
	int ans2 = 0;
	rep(i,N){
		if(i%2 == 0){
			if(S[i] == '0')ans2++;
		}
		else{
			if(S[i] == '1')ans2++;
		}
	}
	int ans = min(ans1,ans2);
	cout<<ans<<endl;
}