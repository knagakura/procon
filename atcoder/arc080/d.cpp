#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }

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
int H,W,N;
vector<int> a;
int c[105][105];
int cnt;
bool IsIn(int x,int y){
    return 0<=x&&x<H&&0<=y&&y<W;
}
void dfs(int x,int y,int i){
    if(cnt == a[i])return;
    if(c[x][y]>0)return;
    c[x][y] = i+1;
    cnt++;
    for(int j = 0; j < 4; j++){
        if(IsIn(x + dx[j],y + dy[j])){
            dfs(x + dx[j],y + dy[j], i);
        }
    }
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    cin>>H>>W>>N;
    a.resize(N);
    rep(i,N){
        cin>>a[i];
    }
    rep(i,H)rep(j,W){
        c[i][j] = -1;
    }
    rep(i,N){
        cnt = 0;
        rep(h,H)rep(w,W){
            if(c[h][w] == -1){
                dfs(h,w,i);
                h = w = INF;
            }
        }
    }
    rep(i,H)rep(j,W){
        cout<<c[i][j];
        if(j == W-1)cout<<endl;
        else cout<<" ";
    }
}