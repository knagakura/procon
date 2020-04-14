#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()		//sort(all(vi S)) sort(all(string S))
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }

using P = pair<int, int>;		//P.first, P.second
typedef long long ll;
typedef vector<int> vi;
typedef set<int> seti;
typedef vector<string> vs;

const int MOD = 1e9+7;
const int INF = 1e9;

template<typename T> 
vector<T> factorize(T x, int maxcnt){
    vector<T> v;
    int cnt = 0;
    for (T i = 2; i*i <= x; i++){
        while (x%i == 0&&cnt<maxcnt-1) {
            x /= i;
            v.push_back(i);
            cnt++;
            print(v);
        }
        if (x == 1||cnt == maxcnt-1) break;
    }
    if (x != 1) v.push_back(x);
    print(v);
    return v;
}

int main() {
	int N,K;
	cin>>N>>K;
	vector<int> ans = factorize(N,K);
	int L = ans.size();
	if(L!=K){
		cout<<-1<<endl;
		return 0;
	}
	else if(K == 1){
		cout<<N<<endl;
		return 0;
	}
	print(ans);
	rep(i,L){
		cout<<ans[i];
		if(i<L-1)cout<<" ";
	}
	cout<<endl;
	//cout<<ans<<endl;
}