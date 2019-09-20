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
int board[105][105] = {-1};
int N;
bool In(int x, int y){
    return 0<=x&&x<N&&0<=y&&y<N;
}
int dx[] = {1,2,-1,-2,-2,-1,2,1};
int dy[] = {2,1, 2, 1,-1,-2,-1,-2};
int main() {
    cin>>N;
    rep(i,N)rep(j,N){
        board[i][j] = -1;
    }
    board[0][0] = 0;
    queue<P> Q;
    Q.push({0,0});
    while(!Q.empty()){
        auto q = Q.front();
        Q.pop();
        int x = q.first;
        int y = q.second;
        rep(i,8){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(!In(nx,ny))continue;
            if(board[nx][ny] != -1)continue;
            board[nx][ny] = 1-board[x][y];
            Q.push({nx,ny});
        }
    }
    /*
    rep(i,N)rep(j,N){
        cerr<<board[i][j];
        if(j == N-1)cerr<<endl;
        else{
            cerr<<" ";
        }
    }
    */
    rep(i,N)rep(j,N){
        if(board[i][j] == 1){
            cout<<'B';
        }
        else{
            cout<<"W";
        }
        if(j == N-1){
            cout<<endl;
        }
    }
}