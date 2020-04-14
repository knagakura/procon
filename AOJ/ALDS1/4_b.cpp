#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()		//sort(all(vi S)) sort(all(string S))
//#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
//#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }

//using P = pair<int, int>;		//P.first, P.second
typedef long long ll;
typedef vector<int> vi;
typedef set<int> seti;
typedef vector<string> vs;

const int MOD = 1e9+7;
const int INF = 1e9;

int main() {
	int N;
	cin>>N;
	vector<int> S(N);
	rep(i,N)cin>>S[i];
	int q;cin>>q;
	vector<int> T(q);
	rep(i,q)cin>>T[i];
	sort(all(T));
	sort(all(S));
	//print(S);print(T);
	int ans = 0;
	rep(i,q){
		int l = 0, r = N;
		int mid = (l+r)/2;
		while(l<r){
			mid = (l+r)/2;
			if(S[mid] == T[i]){
				ans++;
				break;
			}
			else if(T[i]<S[mid]){
				r = mid;
			}
			else{
				l = mid+1;
			}
		}
	}
	cout<<ans<<endl;
}