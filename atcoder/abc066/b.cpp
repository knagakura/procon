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
const int inf = 1e9;

int main() {
	string S;
	cin>>S;
	int ans;
	int N = S.size();
	rep1(i,N){
		string Sn=S.substr(0,N-i);
		int Nn=Sn.size();
		if(Nn%2==0&&Sn.substr(0,Nn/2)==Sn.substr(Nn/2,Nn/2)){
			ans = Nn;
			break;
		}
	}
	cout<<ans<<endl;
}