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

int N;
int main() {
	cin>>N;
	int cnt =0;
	if(N%2 == 0){
		rep1(i,N+1)rep1(j,N+1){
			if(i<j)
			if(i+j!=N+1){
				cnt++;
				//cout<<i<<' '<<j<<endl;
			}
		}
	}
	else{
		rep1(i,N+1)rep1(j,N+1){
			if(i<j)
			if(i+j!=N){
				cnt++;
				//cout<<i<<' '<<j<<endl;
			}
		}
	}
	cout<<cnt<<endl;

	if(N%2 == 0){
		rep1(i,N+1)rep1(j,N+1){
			if(i<j)
			if(i+j!=N+1){
				//cnt++;
				cout<<i<<' '<<j<<endl;
			}
		}
	}
	else{
		rep1(i,N+1)rep1(j,N+1){
			if(i<j)
			if(i+j!=N){
				//cnt++;
				cout<<i<<' '<<j<<endl;
			}
		}
	}

}