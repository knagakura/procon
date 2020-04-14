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
	string N;
	cin>>N;
	int L = N.size();
	vector<int> A;
	rep(i,L){
		A.push_back(N[i] - '0');
	}
	rep(i,L){
		Nsum += N[i] - '0';
	}
	cerr<<Nsum<<endl;

	for (int i = L-1; i >= 1; --i){

	}
	print(A);
}