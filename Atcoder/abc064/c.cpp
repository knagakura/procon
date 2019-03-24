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
	vector<int> a(N);
	vector<bool> f(9);
	int any = 0;
	rep(i,N){
		cin>>a[i];
		if(a[i]>=3200)any++;
		else{
			rep(j,8){
				if(j*400<=a[i]&&a[i]<(j+1)*400){
					f[j] = true;
					break;
				}
			}
		}
	}
	int cnt = 0;
	rep(i,8){
		if(f[i])cnt++;
	}
	int ansmin = max(cnt,1);//1は下回らない
	int ansmax = cnt+any;
	cout<<ansmin<<' '<<ansmax<<endl;
}