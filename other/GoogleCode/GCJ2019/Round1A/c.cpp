#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()		//sort(all(vi S)) sort(all(string S))

typedef long long ll;
typedef vector<int> vi;
typedef set<int> seti;
typedef vector<string> vs;
// language has an accent on exactly one position
// the part of the word starting from the accented letter is called 
// the accent-suffix

lib
const int MOD = 1e9+7;
const int INF = 1e9;
int T,N;
vector<string> W(1005);
int a,ans1,ans2;
void solve(int t){
	cin>>N;
	rep(i,N){
		cin>>W[i];
		reverse(all(W[i]));
	}
	int table[1005][1005];
	rep(i,N)rep(j,N)table[i][j] = 0;
	rep(i,N)rep(j,N){
		if(i>=j)continue;
		int L = min(W[i].size(),W[j].size());
		int l = 0;
		rep(k,L+1){
			string s1 = W[i].substr(0,k);
			string s2 = W[j].substr(0,k);
			//cout<<s1<<endl<<s2<<endl<<endl;
			//cout<<s1<<endl<<s2<<endl<<endl;
			if(s1 == s2){
				//cout<<k<<endl;
				l = max(l,k);
			}
			table[i][j] = max(table[i][j],l);
		}
	}



	rep(i,N){
		rep(j,N){
			cout<<table[i][j]<<" ";;
		}
		cout<<endl;
	}
	//cout<<"Case #"<<t<<": "<<ans1<<" "<<ans2<<endl;;
}




int main() {
	cin>>T;
	rep1(i,T+1){
		solve(i);
	}
}