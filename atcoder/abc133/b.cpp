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

int X[100][100];
int main() {
	int N,D;
	cin>>N>>D;
	rep(i,N)rep(j,D){
		cin>>X[i][j];
	}
	int ans = 0;
	rep(i,N){
		rep(j,N){
			if(i == j)continue;
			int res = 0;
			rep(k,D){
				res += (X[i][k] - X[j][k])*(X[i][k] - X[j][k]);
			}
			double aaa = sqrt(res);
			if(aaa == int(aaa)){
				ans++;
				//cerr<<i<<" "<<j<<endl;
			}
		}
	}
	cout<<ans/2<<endl;
}