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
	string N;
	string ans = "NO";
	cin>>N;
	if(N == "7" or N == "3" or N == "5")ans = "YES";

	cout<<ans<<endl;
}