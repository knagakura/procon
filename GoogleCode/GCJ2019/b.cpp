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
int T;
int N,M;
string S;

bool rival[10005][10005];
bool table[10005][10005];

string ans;

void solve(int Tn){
	cin>>N>>S;
	M = S.size();
	//今いる場所
	//ライバルの通った経路のメモ
	int x = 0,y = 0;
	rival[0][0] = true;
	rep(i,M){
		if(S[i] == 'S'){
			rival[x+1][y] = true;
			x++; 
		}
		else{
			rival[x][y+1] = true;
			y++;
		}
	}
	//なるべく右に行って
	//重なったら下に行く
	rep(i,M){

	}
	cout<<"Case #"<<Tn<<": "<<ans<<endl;;
}

int main() {
	cin>>T;
	rep(t,T){
		solve(t+1);
	}
	cout<<ans<<endl;
}