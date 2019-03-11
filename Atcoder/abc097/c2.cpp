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
	int K;
	cin>>S>>K;
	int N = S.size();
	vector<string> vs;
	for (int i = 0; i < N; ++i){
		for (int j = 0; i+j <= N&& j <=K; ++j){
			vs.push_back(S.substr(i,j));
		}
	}

	set<string> ss(all(vs));
	vector<string> vs2(all(ss));
	sort(all(vs2));
	cout<<vs2[K]<<endl;
}