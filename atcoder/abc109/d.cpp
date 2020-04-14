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
int a[540][540];
int H,W;
bool is_in(int x, int y){
	return 0<=x&&x<H&&0<=y&&y<W;
}
int main() {
	cin>>H>>W;
	rep(i,H)rep(j,W){
		cin>>a[i][j];
	}
	vector<int> x1,y1,x2,y2;
	rep(i,H)rep(j,W-1){
		if(a[i][j]%2==1){
			a[i][j]--;
			a[i][j+1]++;
			x1.push_back(i+1);
			y1.push_back(j+1);
			x2.push_back(i+1);
			y2.push_back(j+2);
			//cout<<i+1<<" "<<j+1<<" "<<i+1<<" "<<j+2<<endl;
		}
	}
	rep(i,H-1){
		if(a[i][W-1]%2==1){
			a[i][W-1]--;
			a[i+1][W-1]++;
			//cout<<i+1<<" "<<W<<" "<<i+2<<" "<<W<<endl;
			x1.push_back(i+1);
			y1.push_back(W);
			x2.push_back(i+2);
			y2.push_back(W);
		}
	}
	int N = x1.size();
	cout<<N<<endl;
	rep(i,N){
		cout<<x1[i]<<" "<<y1[i]<<" "<<x2[i]<<" "<<y2[i]<<endl;
	}
}