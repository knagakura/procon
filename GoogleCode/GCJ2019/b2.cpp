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
int T;
int N;
string S;

void ans(string s){
	int M = s.size();
	rep(i,M){
		if(s[i] == 'S')cout<<'E';
		else cout<<'S';
	}
}
void solve(int Tn){
	cin>>N>>S;
	cout<<"Case #"<<Tn<<": ";
	ans(S);
	cout<<endl;;
}

int main() {
	cin>>T;
	rep(t,T){
		solve(t+1);
	}
}