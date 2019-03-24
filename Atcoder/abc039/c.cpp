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
	vector<string> v = {"Do","Hoge","Re","Hoge","Mi","Fa","Hoge","So","Hoge","La","Hoge","Si"};
	string T = "WBWBWWBWBWBWWBWBWWBWBWBWWBWBWWBWBWBWWBWBWWBWBWBW";
	int ans;
	rep(i,12){
		string t = T.substr(i,12);
		string s = S.substr(0,12);
		//cout<<t<<endl;
		if(s == t){
			ans = i;
			break;
		}
	}
	cout<<v[ans]<<endl;
}