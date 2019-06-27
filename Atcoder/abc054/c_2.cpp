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
int d[100][100];
int main() {
	int N,M;
	cin>>N>>M;
	rep(i,N)rep(j,N){
		d[i][j] = 0;
	}
	rep(i,M){
		int a,b;
		cin>>a>>b;
		a--;b--;
		d[a][b] = d[b][a] = 1;
	}
	/*
	昇順にソート済みのvector（またはstring）を入れると
	辞書順で次の並びのvectorに置き換えてくれる
	辞書順最後になったら -1 を返し止まる
	*/
	vector<int> v;
	rep(i,N){
		v.push_back(i);
	}
	sort(all(v));
	int ans = 0;
	do{
		int cnt = 0;
		for (int i = 0; i < N-1; ++i){
			if(d[v[i]][v[i+1]])cnt++;
		}
		if(v[0] == 0&&cnt == N-1){
			ans++;
			/*print(v);*/
		}
	}while(next_permutation(all(v)));
	cout<<ans<<endl;
}