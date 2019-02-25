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

	vector<int> A(3);
	vector<bool> Af(3);
	cin>>A[0]>>A[1]>>A[2];

	vector<int> l(N);
	vector<bool> lf(N);
	rep(i,N)cin>>l[i];

	sort(all(l));
	int ans=0;
	//含まれてるやつの処理
	rep(i,3)rep(j,N){
		if(A[i]==l[j]&&Af[i]==false&&lf[j]==false){
			cout<<A[i]<<l[j]<<endl;
			Af[i]=true;
			lf[j]=true;
		}
	}
	
	//全部使ったら
	if(Af[0]&&Af[1]&&Af[2])cout<<ans<<endl;
}