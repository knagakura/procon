#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()		//sort(all(vi S)) sort(all(string S))

typedef long long ll;
typedef vector<int> vi;
typedef set<int> seti;
typedef vector<string> vs;
using P = pair<int,int>;
typedef vector<P> vp;

const int MOD = 1e9+7;
const int INF = 1e9;

int main() {
	int N;
	cin>>N;
	vector<pair<int,pair<int,int>>> ab(N),cd(N);
	rep(i,N){
		ll a,b;
		cin>>a>>b;
		ab[i] = {a+b,{a,b}};
	}
	rep(i,N){
		ll c,d;
		cin>>c>>d;
		cd[i] = {c+d,{c,d}};
	}

	sort(all(ab));
	sort(all(cd));

	int ans = 0;
	vector<bool> f(N, true);
	rep(i,N){
		ll a = ab[N-1-i].second.first,b = ab[N-1-i].second.second;
		rep(j,N){
			ll c = cd[j].second.first,d = cd[j].second.second;
			if(a<c&&b<d&&f[j]){
				f[j] = false;
				ans++;
				break;
			}
		}
	}
	cout<<ans<<endl;
}