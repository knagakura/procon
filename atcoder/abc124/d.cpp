#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()		 //sort(all(vi S)) sort(all(string S))
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }

using P = pair<int, int>;		//P.first, P.second
typedef long long ll;
typedef vector<int> vi;
typedef set<int> seti;
typedef vector<string> vs;

const int MOD = 1e9+7;
const int INF = 1e9;

ll gcd(ll a,ll b){
	if(b == 0) return a;
	return gcd(b, a%b);
}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int main() {
	int N,K;
	cin>>N>>K;
	string S;
	cin>>S;
	vi v;
	int cnt = 0;
	int now = 1;
	for(int i = 0; i < N; ++i){
		if(S[i] == char(now + '0')){
			cnt++;
		}
		else{
			v.push_back(cnt);
			now = 1 - now;
			cnt = 1;
		}
	}
	if(cnt!=0){
		v.push_back(cnt);
	}
	if(v.size()%2 == 1){
		v.push_back(0);
	}
	//累積和
	vi cum((int)v.size()+1);
	for(int i = 0; i < (int)v.size(); ++i){
		cum[i+1] = v[i]+cum[i];
	}
	print(v);
	print(cum);
	int tmp = 0;
	int ans = 0;
	for(int i = 0; i < v.size(); i+=2){
		int left = i;
		int right = min(i + 2*K+1, (int)v.size());
		tmp = cum[right]-cum[left];
		ans = max(tmp, ans);
	}

	cout<<ans<<endl;
}