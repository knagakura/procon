#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define all(a) (a).begin(),(a).end()		//sort(all(vi S)) sort(all(string S))

using P = pair<int, int>;		//P.first, P.second
typedef long long ll;

int main() {
	int N;
	cin>>N;
	vector<int> v1,v2;
	std::map<ll, ll> map1,map2;
	rep(i,N){
		int v;
		cin>>v;
		if(i%2 == 0){
			v1.push_back(v);
			map1[v]++;
		}
		else{
			v2.push_back(v);
			map2[v]++;
		}
	}
	vector<P> cnt1,cnt2;
	//個数、keyのPairのベクター
	for(auto x :  map1){
		cnt1.emplace_back(x.second,  x.first);
	}
	for(auto x :  map2){
		cnt2.emplace_back(x.second,  x.first);
	}
	cnt1.push_back({0,0});
	cnt2.push_back({0,0});
	sort(all(cnt1));
	sort(all(cnt2));
	int ans  = N;
	int N1 = cnt1.size();
	int N2 = cnt2.size();
	if(cnt1[N1-1].second==cnt2[N2-1].second){
		ans -= max(cnt1[N1-1].first+cnt2[N2-2].first,cnt1[N1-2].first+cnt2[N2-1].first);
	}
	else{
		ans -= cnt1[N1-1].first+cnt2[N2-1].first;
	}
	cout<<ans<<endl;
}