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
int Grid[5005][5005];
int A[5005][5005];
void dfs(int x, int y, int cnt){
    A[x][y] = cnt;
    Grid[x][y]++;
    if(Grid[x+1][y+1] == 1){
        dfs(x+1, y+1, cnt+1);
    }
}
int main() {
    int N;
    cin>>N;
    string S;
    cin>>S;
    rep(i,N)rep(j,N){
        if(i == j)Grid[i][j] = 0;
        else{
            if(S[i] == S[j]){
                Grid[i][j] = 1;
            }
        }
    }
    rep(i,N)rep(j,N){
        if(Grid[i][j] == 1){
            dfs(i,j,1);
        }
    }
    /*
    rep(i,N)rep(j,N){
        cerr<<Grid[i][j];
        if(j == N-1){
            cerr<<endl;
        }
        else{
            cerr<<" ";
        }
    }
    cerr<<endl;
        rep(i,N)rep(j,N){
        cerr<<A[i][j];
        if(j == N-1){
            cerr<<endl;
        }
        else{
            cerr<<" ";
        }
    }
    */
    int ans = 0;
    for(int i = 0; i < N; ++i){
        for(int j = i+1; j < N; ++j){
            int r1 = i,r2 = j;
            int l1 = r1 - A[i][j] + 1;
            int l2 = r2 - A[i][j] + 1;
            if(r1 < l2){
                ans = max(ans, A[i][j]);
            }
            else if(r2 < l1){
                ans = max(ans, A[i][j]);
            }
        }
    }
    cout<<ans<<endl;

}