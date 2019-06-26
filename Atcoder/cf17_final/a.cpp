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
	vector<string> v;
	v.push_back("AKIHABARA");

	v.push_back("KIHABARA");
	v.push_back("AKIHBARA");
	v.push_back("AKIHABRA");
	v.push_back("AKIHABAR");

	v.push_back("KIHBARA");
	v.push_back("KIHABRA");
	v.push_back("KIHABAR");
	v.push_back("AKIHBRA");
	v.push_back("AKIHBAR");
	v.push_back("AKIHABR");

	v.push_back("KIHBRA");
	v.push_back("KIHBAR");
	v.push_back("AKIHBR");
	v.push_back("KIHABR");

	v.push_back("KIHBR");

	rep(i,(int)v.size()){
		if(S == v[i]){
			cout<<"YES"<<endl;
			return 0;
		}
	}
	cout<<"NO"<<endl;
}