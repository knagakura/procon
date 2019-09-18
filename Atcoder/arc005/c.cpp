#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()		 //sort(all(vi S)) sort(all(string S))
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }

using P = pair<int, int>;		//P.first, P.second
typedef long long ll;
typedef vector<int> vi;
typedef set<int> seti;
typedef vector<string> vs;

const int MOD = 1e9+7;
const int INF = 1e9;
int H,W;
vs c(540);
int dx[4] = {0,1,0,-1};
int dy[4] = {1,0,-1,0};
int cost[504][504];
bool seen[504][504] = 
bool IsIn(int x, int y){
    if(0<=x&&x<H&&0<=y&&y<W)return true;
    else return 0;
}

int main() {
    cin>>H>>W;
    rep(i,H)cin>>c[i];
    queue<P> Q;
    rep(i,H)rep(j,W){
        if(c[i][j] == 's'){
            Q.push({i,j});
        }
    }
    while(not Q.empty()){
        int nowx = Q.front().first;
        int nowy = Q.front().second;
        Q.pop();
        rep(i,4){
            int nx = nowx + dx[i];
            int ny = nowy + dy[i];
            if(IsIn(nx,ny)){
                
            }
        }
    }
}