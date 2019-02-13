#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()

typedef long long ll;
typedef vector<int> vi;
typedef set<int> seti;
typedef vector<string> vs;

const ll MOD = 1e9+7;
const int inf = 1e8;

int main() {
	int N;
	cin>>N;
	ll ans=1;
	rep1(i,N+1){
		ans =ans*i%MOD;
	}
	cout<<ans<<endl;
}