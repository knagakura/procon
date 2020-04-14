#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()		//sort(all(vi S)) sort(all(string S))

typedef long long ll;
typedef vector<int> vi;
typedef set<int> seti;
typedef vector<string> vs;

const int MOD = 1e9+7;
const int INF = 1e9;

int main() {
	int N;
	cin>>N;
	vector<int> v(N);
	rep(i,N)cin>>v[i];
	int ans = INF;
	for (int i = 0; 2*i < N; ++i){
		int cnt = 0;
		int a = v[2*i],b = v[2*i+1];
		if(a!=b){
			for (int j = 0; j < N; ++j){
				if(j%2 ==0){
					if(v[j]!=a)cnt++;
				}
				else{
					if(v[j]!=b)cnt++;
				}
			}
			ans = min(ans,cnt);
		}
	}
	if(ans == INF)ans = N/2;
	cout<<ans<<endl;
}