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
int d[108][108];

int main() {
	int N,K;
	cin>>N>>K;
	if(K>(N-1)*(N-2)/2){
		cout<<-1<<endl;
		return 0;
	}

	for (int i = 0; i < N; ++i){
		for (int j = i+1; j < N; ++j){
			d[i][j] = 1;
		}
	}
	int cnt = 0;
	for (int i = 1; i < N-1; ++i){
		for (int j = i+1; j < N; ++j){
			if(cnt >= K)i=N,j=N;
			d[i][j] = 0;
			cnt++;
		}
	}
	int M = 0;
	for (int i = 0; i < N; ++i){
		for (int j = i+1; j < N; ++j){
			if(d[i][j])M++;
		}
	}
	cout<<M<<endl;
	for (int i = 0; i < N; ++i){
		for (int j = i+1; j < N; ++j){
			if(d[i][j]){
				cout<<i+1<<" "<<j+1<<endl;
			}
		}
	}
	for (int i = 0; i < N; ++i){
		for (int j = 0; j < N; ++j){
			cerr<<d[i][j]<<" ";
		}
		cerr<<endl;
	}
}
