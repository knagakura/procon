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
	int N=S.size();
	int ans;
	vector<int> f(N);
	rep(i,N)rep(j,N){
		if(S[i]=='2'){
			if(f[j]%2==0){
				f[j]++;
				break;
			}
		}
		else{
			if(f[j]%2==1){
				f[j]++;
				break;
			}
		}
	}
	rep(i,N){
		if(f[i]%2==0)ans++;
	}
	cout<<ans<<endl;
}
//vectorで部分文字列を持っておいて2と5が出てきているかどうかを