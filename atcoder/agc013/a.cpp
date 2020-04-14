#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()		//sort(all(vi S)) sort(all(string S))
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }

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
	vector<ll> A(N);
	rep(i,N)cin>>A[i];
	A.push_back(A[N-1]);
	A.push_back(A[N-1]);
	bool zouka, gensyo;
	int start = N;
	rep(i,N-1){
		if(A[i]!=A[i+1]){
			start = i;
			zouka = A[i]<A[i+1];
			gensyo = A[i]>A[i+1];
			break;
		}
	}

	if(start == N){
		cout<<1<<endl;
		return 0;
	}

	int ans = 1;
	for (int i = start; i < N; ++i){
		if(A[i] == A[i+1]){
			zouka = gensyo = false;
			continue;
		}
		if(zouka&&A[i]>A[i+1]){
			zouka = A[i+1]<A[i+2];
			gensyo = A[i+1]>A[i+2];
			ans++;
			cerr<<"zouka -> gensyo: "<<i+1<<"番目"<<A[i]<<" "<<A[i+1]<<endl;
			i++;
			continue;
		}
		if(gensyo&&A[i]<A[i+1]){
			gensyo = A[i+1]>A[i+2];
			zouka = A[i+1]<A[i+2];
			ans++;
			cerr<<"gensyo -> zouka: "<<i+1<<"番目"<<A[i]<<" "<<A[i+1]<<endl;
			i++;
			continue;
		}
	}
	cout<<ans<<endl;
}