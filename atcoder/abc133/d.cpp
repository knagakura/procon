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
	vector<ll> A(N);
	rep(i,N)cin>>A[i];
	vector<ll> V(N);
	V[0] = 2*A[0];
	rep(i,N-1){
		V[i+1] = 2*A[i+1] - V[i];
	}
	vector<ll> Mt(N);
	ll i = 0;
	ll maxx = 2*A[0];
	while(true){
		//if(i%2 == 1)continue;
		Mt[0] = i;
		Mt[N-1] = V[N-2];
		if((N-1)%2 == 0){
			Mt[N-1] += Mt[0];
		}
		else{
			Mt[N-1] -= Mt[0];
		}
		if(A[N-1] == Mt[N-1]/2+Mt[0]/2){
			break;
		}
		if(A[N-1]<Mt[N-1]/2+Mt[0]/2){
			i = maxx;
		}
		else{
			maxx = i/2;
			i = maxx;
		}
	}
	rep(i,N-2){
		Mt[i+1] = V[i];
		if((i+1)%2 == 0)Mt[i+1]+=Mt[0];
		else Mt[i+1]-=Mt[0];
	}
	rep(i,N){
		if(i==N-1){
			cout<<Mt[i]<<endl;
			return 0;
		}
		cout<<Mt[i]<<" ";
	}
}