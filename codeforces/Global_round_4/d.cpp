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
int Graph[1080][1080];
bool IsPrime(int x){
	if(x < 2)return false;
	else if(x % 2 == 0)return false;
	for (int i = 3; i*i <= x; ++i){
		if(x % i == 0){
			return false;
		}
	}
	return true;
}

int main() {
	int N;cin>>N;
	int H = N;
	int W = N;
	int cnt = 0;
	rep(i,H)rep(j,W){
		if(i < j){
			Graph[i][j] = 1;
			cnt++;
		}
		else{
			Graph[i][j] = 0;
		}
	}
	rep(i,H)rep(j,W-1){
		if(i < j){
			Graph[i][j] = 0;
			cnt--;
			if(IsPrime(cnt)){
				i = INF;
				j = INF;
			}
		}
	}
	cout<<cnt<<endl;
	rep(i,H)rep(j,W){
		if(i<j&&Graph[i][j]){
			cout<<i+1<<" "<<j+1<<endl;
		}
	}
}