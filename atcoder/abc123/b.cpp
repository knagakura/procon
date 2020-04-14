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

vector<int> v(10);
vector<int> b(10);
int main() {
	rep(i,5)cin>>v[i];

	rep(i,5){
		b[i] = v[i]%10;
	}

	int cnt = 0;
	rep(i,5){
		if(b[i]==0)cnt++;
	}
	int ans = 0;
	if(cnt == 5){
		rep(i,5)ans+=v[i];
		cout<<ans<<endl;
		return 0;
	}
	int ind = 0;
	int minb = INF;
	rep(i,5){
		if(b[i]>0&&minb>b[i]){
			ind = i;
			minb = min(b[i],minb);
		}
	}
	rep(i,5){
		if(b[i]==0||i == ind)ans+=v[i];
		else{
			ans+= v[i]-b[i]+10;
		}
	}
	cout<<ans<<endl;
}