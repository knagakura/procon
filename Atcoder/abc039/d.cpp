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
int H,W;
vector<string> S,T,U;
bool isin(int x,int y){
    return 0<=x&&x<H&&0<=y&&y<W;
}
void debug(vector<string> &X){
    rep(i,H){
        cerr<<X[i]<<endl;
    }
    cerr<<endl;
}

bool check(int i, int j){
    bool _all = true;
    rep(k,8){
        int nx = i + dx[k];
        int ny = j + dy[k];
        if(!isin(nx, ny))continue;
        if(S[nx][ny] == '.'){
            _all = false;
        }
    }
    return _all;
}
void paint(int i, int j){
    U[i][j] = '#';
    rep(k,8){
        int nx = i + dx[k];
        int ny = j + dy[k];
        if(!isin(nx, ny))continue;
        U[nx][ny] = '#';
    }
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    
    cin>>H>>W;
    string t = "";
    rep(_, W)t += ".";
    S.resize(H);
    T.assign(H,t);
    U.assign(H,t);
    rep(i,H){
        cin>>S[i];
    }
    rep(i,H)rep(j,W){
        if(S[i][j] == '#' && check(i,j)){
            T[i][j] = '#';
            paint(i,j);
        }
    }

    debug(S);debug(T);

    debug(U);
    if(S == U){
        cout<<"possible"<<endl;
        rep(i,H){
            cout<<T[i]<<endl;
        }
    }
    else{
        cout<<"impossible"<<endl;
    }
}