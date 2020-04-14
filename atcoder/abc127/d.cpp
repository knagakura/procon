#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()		//sort(all(vi S)) sort(all(string S))
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printp(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }

using P = pair<int, int>;		//P.first, P.second
typedef long long ll;
typedef vector<int> vi;
typedef set<int> seti;
typedef vector<string> vs;

const int MOD = 1e9+7;
const int INF = 1e9;
//B枚までCに書き換えることができるよ！
int main() {
	ll N,M;
	cin>>N>>M;
	vector<ll> A(N),B(M),C(M);
	priority_queue<ll, vector<ll>, greater<ll>> pq;
	rep(i,N){
		cin>>A[i];
		pq.emplace(A[i]);
	}
	sort(all(A));
	print(A); 
	vector<P> CB;
	rep(i,M){
		cin>>B[i]>>C[i];
		CB.push_back({C[i],B[i]});
	}
	sort(all(CB), greater<P>());
	printp(CB);
	int cnt = 0;
	rep(i,M){
		ll c = CB[i].first, b = CB[i].second;
		rep(j,b){
			ll minn = pq.top();pq.pop();
			pq.emplace(max(minn,c));
			cnt++;
			if(cnt==N)i = M,j = b;
		}
	}
	ll ans = 0;
	while(!pq.empty()){
		ans+=pq.top();pq.pop();
	}
	cout<<ans<<endl;
}