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
int row[2005][2005];
int col[2005][2005];
int main() {
	int H,W;
	cin>>H>>W;
	vs S(H);
	rep(i,H){
		cin>>S[i];
	}
	//row
	rep(i,H){
		if(S[i][0] == '.'){
			row[i][0] = 1;
		}
	}
	rep(i,H){
		rep1(j,W){
			if(S[i][j]=='#'){
				row[i][j] = 0;
			}
			else{
				row[i][j] = row[i][j-1]+1;
			}
		}
	}

	rep(j,W){
		if(S[0][j] == '.'){
			col[0][j] = 1;
		}
	}
	rep1(i,H){
		rep(j,W){
			if(S[i][j] == '#'){
				col[i][j] = 0;
			}
			else{
				col[i][j] = col[i-1][j] + 1;
			}
		}
	}
/*
	rep(i,H){
		rep(j,W){
			cerr<<col[i][j]<<" ";
		}
		cerr<<endl;
	}
	cerr<<endl;
	rep(i,H){
		rep(j,W){
			cerr<<row[i][j]<<" ";
		}
		cerr<<endl;
	}
	cerr<<endl;
*/	for (int i = H-2; i > -1; --i){
		rep(j,W){
			if(col[i+1][j]>0&&col[i][j]>0)col[i][j] = col[i+1][j];
		}
	}
	rep(i,H){
		for (int j = W-2; j>-1; --j){
			if(row[i][j+1]>0&&row[i][j]>0)row[i][j] = row[i][j+1];
		}
	}/*
	rep(i,H){
		rep(j,W){
			cerr<<col[i][j]<<" ";
		}
		cerr<<endl;
	}
	cerr<<endl;
	rep(i,H){
		rep(j,W){
			cerr<<row[i][j]<<" ";
		}
		cerr<<endl;
	}*/
	int ans = 0;
	rep(i,H)rep(j,W){
		ans = max(ans, row[i][j] + col[i][j] -1);
	}
	cout<<ans<<endl;
}