#include <bits/stdc++.h>
using namespace std;

#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)


typedef long long ll;
typedef vector<int> vi;
typedef set<int> seti;
typedef vector<string> vs;

const int MOD = 1e9+7;
const int INF = 1e9;

vector<int> Iv;
vector<int> Jv;
int N;
int main() {
	cin>>N;
	int X = N;
	if(N%2 == 0)X = N+1;

	int cnt =0;
	rep1(i,N+1)rep1(j,N+1){
		if(i<j)if(i+j!=X){
			cnt++;
			Iv.push_back(i);
			Jv.push_back(j);
		}
	}

	cout<<cnt<<endl;

	rep(i,cnt){
		cout<<Iv[i]<<' '<<Jv[i]<<endl;
	}
}