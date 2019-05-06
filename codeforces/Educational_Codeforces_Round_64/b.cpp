#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()		//sort(all(vi S)) sort(all(string S))
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define uniq(a) a.erase(unique(all(a)),a.end())

using P = pair<int, int>;		//P.first, P.second
typedef long long ll;
typedef vector<int> vi;
typedef set<int> seti;
typedef vector<string> vs;

const int MOD = 1e9+7;
const int INF = 1e9;
void solve(string S){
	sort(all(S));
	/*cerr<<"S: "<<S<<endl;*/
	int N = S.size();
	map<char, int> mpcnt;
	vector<char> v;
	rep(i,N){
		mpcnt[S[i]]++;
		v.push_back(S[i]);
	}
	uniq(v);

	map <char,bool> mpf;
	rep(i,N-1){
		if(S[i+1]-S[i] == 1){
/*			cerr<<"yes :"<<S[i]<<S[i+1]<<endl;
*/			mpf[S[i]] =true;
			mpf[S[i+1]] = true;
		}
		if(S[i+1]-S[i] !=1&&S[i+1] != S[i]){
			mpf[S[i]] =false;
/*			cerr<<"not :"<<S[i]<<S[i+1]<<endl;
*/		}
	}
	/*print(v);*/
	string S1 = "",S2 = "";
	int cnt = 0;
	int M = v.size();
	rep(i,M){
		if(mpf[v[i]]==true){
			if(cnt%2 == 0){
				rep(j,mpcnt[v[i]])
				S2 += v[i];
			}
			else{
				rep(j,mpcnt[v[i]])
				S1 +=v[i];
			}
			cnt++;
		}
		if(mpf[v[i]] == false){
			rep(j,mpcnt[v[i]])
			S1+=v[i];
			cnt = 0;
		}
	}
	string ans = S1+S2;
	if(M == 2&&v[1]-v[0] == 1){
		cout<<"No answer"<<endl;
		return;
	}
	if(M==3&&v[2]-v[1] == 1&&v[1]-v[0] == 1){
		cout<<"No answer"<<endl;
		return;
	}
	cout<<ans<<endl;
}
int main() {
	int T;
	cin>>T;
	vector<string> S(T);
	rep(i,T)cin>>S[i];
	rep(i,T){
		solve(S[i]);
	}
}