#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define bit(k) (1LL<<(k))
typedef long long ll;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = 1e9;
const ll INFLL = 1e18;
const ll MOD = 1e9+7;
const double PI = acos(-1.0);

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};

/*------------------------------------/
for library*/

/*------------------------------------*/
int W,H;
string memo[100][100];
vector<string> C;
vector<string> ans;
bool IsIn(int x,int y){
    return 0<=x&&x<H&&0<=y&&y<W;
}
string _max(string a,string b){
    if(a.size() > b.size())return a;
    if(a.size() < b.size())return b;
    return max(a,b);
}
string dfs(int x, int y,string S){
    S.push_back(C[x][y]);
    int cnt = 0;
    string tmp = S;
    if(memo[x][y] != "")return memo[x][y];
    rep(i,2){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(IsIn(nx,ny)){
            if('0'<=C[nx][ny]&&C[nx][ny]<='9'){
                memo[x][y] = _max(S,dfs(nx,ny,tmp));
                cnt++;
            }
        }
    }
    return memo[x][y];
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    while(1){
        rep(i,100)rep(j,100){
            memo[i][j] = "";
        }
        cin>>W>>H;
        if(W == 0 && H == 0)break;
        C.assign(H,"");
        rep(i,H){
            cin>>C[i];
        }
        string res = "";
        rep(i,H)rep(j,W){
            if(memo[i][j] == ""){
                if('1'<=C[i][j]&&C[i][j]<='9'){
                    res = _max(res,dfs(i,j,""));
                }
            }
        }
        cout<<res<<endl;
    }
}