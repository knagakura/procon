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
	int N = S.size();
	int cnt = INF;
	while(cnt>0){
		cnt = 0;
		rep(i,N-1){
			if(S[i]=='W'&&S[i+1]=='A'){
				cnt++;
			}
		}
	}
	cout<<ans<<endl;
}