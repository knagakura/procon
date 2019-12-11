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
	int w1,h1,w2,h2;
	cin>>w1>>h1>>w2>>h2;
	int ans = w1+2 + w2+2 + 2*(h1+h2) + w1-w2;
	cout<<ans<<endl;
}