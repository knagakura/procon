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
ll w1 = 0;
ll w,v;

int main() {
	ll N,W;
	cin>>N>>W;
	vector<P> wv;
	map<ll, ll> map;
	rep(i,N){
		cin>>w>>v;
		if(i == 0)w1 = w;
		wv.push_back({w,v});
		map[w-w1]++;
	}
	sort(all(wv));
	cerr<<w1<<endl;
	printpair(wv);
	//上位何個まで足したかの累積和配列を4つ持つ
	//w+iの重さのものを上位j個まで足した配列cumsum[i][j]
	ll cumsum[4][108];
	//初期化
	for (int i = 0; i < 4; ++i){
		cumsum[i][0] = 0;
	}
	int cnt = 1;
	for (int i = N-1; i >= 0; --i){
		cumsum[wv[i].first-w1][cnt] = cumsum[wv[i].first-w1][cnt-1] + wv[i].second;
		if(i == 0)break;
		if(wv[i].first == wv[i-1].first){
			cnt++;
		}
		else{
			cnt = 1;
		}
	}
	ll ans = 0;
	rep(i,map[0]+1)rep(j,map[1]+1)rep(k,map[2]+1)rep(l,map[3]+1){
		ll res = cumsum[0][i] + cumsum[1][j] + cumsum[2][k] + cumsum[3][l];
		ll wsum = i * w1 + j * (w1 + 1) + k * (w1 + 2) + l * (w1 + 3);
		if(wsum<= W){
			ans = max(ans, res);
		}
	}
	cout<<ans<<endl;
}