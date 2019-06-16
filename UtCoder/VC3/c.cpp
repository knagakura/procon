#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()		//sort(all(vi S)) sort(all(string S))
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }

using P = pair<int, int>;		//P.first, P.second
typedef long long ll;
typedef vector<int> vi;
typedef set<int> seti;
typedef vector<string> vs;

const int MOD = 1e9+7;
const int INF = 1e9;

int main() {
	int N;
	cin>>N;
	vector<string> A;
	A.push_back("a");
	A.push_back("b");
	A.push_back("c");
	rep(i,N-1){
		int M = A.size();
		for (int j = 0; j < M; ++j){
			A.push_back(A[j]+"a");
			A.push_back(A[j]+"b");
			A.push_back(A[j]+"c");
		}
	}
	sort(all(A));
	print(A);
	int L = A.size();
	rep(i,L){
		if(int(A[i].size()) == N){
			cout<<A[i]<<endl;
		}
	}
}