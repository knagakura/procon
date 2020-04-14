#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()		//sort(all(vi S)) sort(all(string S))
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }

typedef long long ll;
typedef vector<int> vi;
typedef set<int> seti;
typedef vector<string> vs;

const int MOD = 1e9+7;
const int INF = 1e9;

template<typename T> 
map<T,int> factorize(T x){
    map<T,int> mp;
    for (T i = 2; i*i <= x; i++){
        while (x%i == 0) {
            x /= i;
            mp[i]++;
        }
        if (x == 1) break;
    }
    if (x != 1) {
    	mp[x]++;
    }
    return mp;
}

int main() {
	ll N, P;
	cin>>N>>P;
	map <ll, int> f = factorize(P);
	if(P==1){
		cout<<1<<endl;
		return 0;
	}
	ll ans = 1;
	for(auto i :f){
		cerr<<i.first<<": "<<i.second<<endl;
		if(i.second >= N){
			for (int j = 0; j < i.second/N; ++j){
				ans*=i.first;
			}
		}
	}
	cout<<ans<<endl;
}