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
	int N,K;
	cin>>N>>K;
	vector<int> f(10);

	rep(i,K){
		int x;
		cin>>x;
		f[x]++;
	}

	for (int i = N;;++i){
		string S = to_string(i);
		bool ok = true;
		for (int j = 0; j < S.size(); ++j){
			if(f[S[j] - '0'])ok = false;
		}
		if(ok){
			cout<<i<<endl;
			break;
		}
	}
}