#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define dump(x) cerr<<#x<<": "<<x<<endl;
#define bit(k) (1LL<<(k))
#define Yes "Yes"
#define No "No"
#define YES "YES"
#define NO "NO"
typedef long long ll;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;

template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = (ll)1e9;
const ll INFLL = (ll)1e18+1;
const ll MOD = (ll)1e9+7;
const double PI = acos(-1.0);

const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const string sdir = "DRUL";

int H,W;           
int dir_v[4][6] =   {{4, 1, 0, 3, 5, 2},
                     {1, 5, 2, 0, 4, 3},
                     {2, 1, 5, 3, 0, 4},
                     {3, 0, 2, 5, 4, 1}
                  };
int v_idx[] = {4, 1, 2, 3};
bool visited[110][110];
bool IsIn(int x,int y){
    return 0<=x&&x<H&&0<=y&&y<W;
}
vector<string> s, tmp;
void debug(){
    rep(i,H){
        cerr << s[i] << endl;
    }
    cerr << endl;
}
bool can_move(vector<int>& v, int nx, int ny, int dir){
    //cerr <<sdir[dir] << endl;
    //dump(v[v_idx[dir]]);
    //cerr << "can_move: " << nx << " " << ny << " " << v[v_idx[dir]] << " " << s[nx][ny] << endl;
    //print(v);
    return v[v_idx[dir]] == s[nx][ny] - '0';
}
 
vector<int> next_v(vector<int>& v, int dir){
    vector<int> res(6, 0);
    rep(i,6){
        res[i] = v[dir_v[dir][i]];
    }
    return res;
}

void dfs(int sx, int sy, vector<int>& t){
    if(visited[sx][sy])return;
    //cerr << endl << "now: " << sx << " " << sy << endl;
    visited[sx][sy] = true;
    rep(i,4){
        int nx = sx + dx[i];
        int ny = sy + dy[i];
        if(!IsIn(nx, ny))continue;
        if(can_move(t, nx, ny, i)){
            vector<int> nv = next_v(t, i);
            dfs(nx, ny, nv);
        }
    }
    return;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    cin >> H >> W;
    s.resize(H);
    rep(i,H)cin >> s[i];
    vector<int> ts = {6, 3, 5, 4, 2, 1};
    rep(i,H)rep(j,W){
        visited[i][j] = false;
    }
    dfs(0, 0, ts);
    if(visited[H-1][W-1]){
        cout << YES << endl;
    }
    else{
        cout << NO << endl;
    }
}