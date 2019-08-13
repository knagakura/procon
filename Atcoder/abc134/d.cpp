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
	//1-indexed
	vector<int> a(N+1);
	rep1(i,N+1)cin>>a[i];
	//print(a);
	vector<int> ans(N+1,0);
	//v[i]:iの約数の列挙（そんなに多くない）
	vector<vector<int>> v(N+1);
	for (int i = 1; i <= N; ++i){
		for (int x = 1; x*x <= i; ++x){
			if(i % x == 0){
				v[i].push_back(x);
				if(x * x != i){
					v[i].push_back(i/x);
				}
			}
		}
	}
/*	for (int i = 1; i <= N; ++i){
		print(v[i]);
 	}*/
	//iの倍数で何個入れたか
	map<int, int> map;
	for (int i = N; i >= 1; --i){
		if(map[i]%2 != a[i]){
				ans[i] = 1;
		}
		if(ans[i]){
			int NN = v[i].size();
			for (int j = 0; j < NN; ++j){
				map[v[i][j]]++;
			}
		}
	}/*
	for (int i = 1; i <= N; ++i){
		cerr<<i<<": "<<map[i]<<endl;
	}*/
	/*print(ans);*/
	int M = 0;
	for (int i = 1; i <= N; ++i){
		if(ans[i])M++;
	}
	cout<<M<<endl;
	for (int i = 1; i <= N; ++i){
		if(ans[i]){
			cout<<i;
			if(i == N)cout<<endl;
			else{
				cout<<" ";
			}
		}
	}
}