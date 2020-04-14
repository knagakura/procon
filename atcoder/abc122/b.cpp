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
	int N = S.size();
	vector<string> ans;
	for (int i = 0; i < N; ++i){
		for (int j = 0; i+j-1 < N; ++j){
			string s = S.substr(i,j);
			int cnt = 0;
			rep(k,j){
				if(s[k]=='A'||s[k]=='T'||s[k]=='G'||s[k]=='C')
					cnt++;
			}
			if(cnt==j)ans.push_back(s);
		}
	}
	sort(all(ans));
	int a = -1;
	rep(i,ans.size()){
		//cout<<ans[i]<<endl;
		//cout<<ans[i].size()<<endl;
		int b = ans[i].size();
		a = max(a ,b);
	}
	cout<<a<<endl;
}