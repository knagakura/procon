//偶数番目の頻度最大と奇数番目の頻度最大
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
	int N;
	cin>>N;
	vector<int> v(N);
	rep(i,N)cin>>v[i];

	vector<int> cnt0(100000),cnt1(100000);
	for (int i = 0; i < N; i+=2){
		cnt0[v[i]]++;
	}
	for (int i = 1; i < N; i+=2){
		cnt1[v[i]]++;
	}

	rep(i,100000){
	}
	cout<<ans<<endl;
}