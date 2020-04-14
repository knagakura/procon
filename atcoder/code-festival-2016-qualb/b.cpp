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
	int N,A,B;
	cin>>N>>A>>B;
	string S;
	cin>>S;
	int cntall=0,cntb=0;
	rep(i,N){
		if(S[i]=='a'&&cntall<A+B){
			cntall++;
			cout<<"Yes"<<endl;
		}
		else if(S[i]=='b'&&(cntall<A+B&&cntb<B)){
			cntall++;
			cntb++;
			cout<<"Yes"<<endl;
		}
		else{
			cout<<"No"<<endl;
		}
	}
}