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
	int H,W;
	cin >> H >> W;
	string S;
	rep(i,H){
		rep(j,W){
			cin>>S;
			if(S =="snuke")
				cout<<char('A'+j)<<i+1;
		}
	}
}