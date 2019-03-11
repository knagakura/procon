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
	string S;
	cin>>S;
	int cnt=0;
	int N = S.size();
	rep(i,N){
		if(S[i]=='W'){
			cnt++;
			if(i==N-1)rep(j,cnt)cout<<'W';
		}
		else if(S[i]=='A'&&cnt){
			cout<<'A';
			rep(j,cnt)cout<<'C';
			cnt = 0;
		}
		else if(cnt&&S[i]!='A'&&S[i]!='W'){
			rep(j,cnt)cout<<'W';
			cout<<S[i];
			cnt = 0;
		}
		else {
			cout<<S[i];
			cnt = 0;
		}
	}
	cout<<endl;
}
//WWW...WA→AAA...AC