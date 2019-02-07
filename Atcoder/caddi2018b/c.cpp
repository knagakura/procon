#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define all(a) (a).begin(),(a).end()

typedef long long ll;
typedef vector<int> vi;
typedef set<int> seti;
typedef vector<string> vs;

const int MOD = 1e9 + 7;
const int inf = 1e8;

int main() {
	ll N,P;
	cin >> N>>P;
	ll rootP = sqrt(P);
	set<int> s;
	rep(i,rootP){
		if(P%(i+1) == 0) s.insert(i);
	}
	cout << s << endl;
}