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
	int H,W;
	cin>>H>>W;
	vector<bool> f(10);
	int A;
	rep(i,H)rep(j,W){
		cin>>A;
		f[A] = true;
	}
	if(!(f[5])){
		cout<<"No"<<endl;
		return 0;
	}
	int cnt5_larger = 0;
	rep(i,10){
		if(i>5&&f[i])cnt5_larger++;
	}
	cout<<"Yes"<<' '<<cnt5_larger+1<<endl;
}