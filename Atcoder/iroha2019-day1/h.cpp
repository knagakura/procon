#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()		//sort(all(vi S)) sort(all(string S))
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }

using P = pair<int, int>;		//P.first, P.second
typedef long long ll;
typedef vector<int> vi;
typedef set<int> seti;
typedef vector<string> vs;

const int MOD = 1e9+7;
const int INF = 1e9;

int main() {
	string N;
	cin>>N;
	int L = N.size();
	int Nsum = 0;
	rep(i,L){
		Nsum += N[i] - '0';
	}
	cerr<<Nsum<<endl;

	int ansl = Nsum/9;
	if(Nsum%9!=0)ansl++;
	vector<int> ans;
	rep(i,ansl){
		if(Nsum>9){
			ans.push_back(9);
			Nsum-=9;
		}
		else ans.push_back(Nsum);
	}
	print(ans);
	int ansn = 0;
	for (int i = int(ans.size())-1; i >=0; --i){
		ansn = ansn*10 + ans[i];
	}
	string anss = to_string(ansn);
	if(anss != N){
		cout<<anss<<endl;
	}
	else{
		
		if(anss[0] == '9'){
			anss[0] = '8';
			cout<<1;
			cout<<anss<<endl;
		}
		else{
			anss[0] +=1;
			anss[1] -=1;
			cout<<anss<<endl; 
		}
	}
	//cout<<ans<<endl;
}