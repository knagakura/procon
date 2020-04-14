#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()		//sort(all(vi S)) sort(all(string S))
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }

using P = pair<int, int>;		//P.first, P.second
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
	int ans = 0;
	int a = 0;
	int bc = 0;
	
/*	for (int i = 0; i < N; ++i){
		if(S[i] == 'A'){
			a++;
			cerr<<"A:" <<i<<endl;
			cerr<<"nA: "<<a<<endl;
			for (int j = i; j+2< N; ++j){
				if(S[j+1] == 'A'){
					if(S[j] != 'A'){
						ans+= a*bc;
					}
					a++;
				}
				else if(a > 0 && S[j+1] == 'B'&&S[j+2] == 'C'){
					cerr<<"BC: "<<j + 1<<endl;
					bc++;
					cerr<<"nBC: "<<bc<<endl;
					if(j+2 == N-1)ans+=a*bc;
					j++;
				}
				else{
					ans += a*bc;
					a = 1;
					bc = 0;
					i = j+2;
					break;
				}
			}
		}
	}*/
	cout<<ans<<endl;
}