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
vector<int> b(110);
vector<int> ans;
int main() {
	cin>>N;
	rep(i,N){
		cin>>b[i];
		b[i]--;
	}
	int cnt = 0;
	for (int i = 0; i < N; ++i){//N回逆から操作を行う
		for (int j = N-1-i; j >= 0; j--){//0~N-1-iのうち、取れるもので最大のものを取ってくる
			if(b[j] == j){
				ans.push_back(b[j]+1);
				b.erase(b.begin() + j);
				cnt++;
				break;
			}
		}
	}
	if(cnt < N){
		cout<<-1<<endl;
		return 0;
	}
	for (int i = N-1; i >= 0; i--){
		cout<<ans[i]<<endl;
	}
}