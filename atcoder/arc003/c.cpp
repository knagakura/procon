#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define dump(x) cerr<<#x<<": "<<x<<endl;
#define bit(k) (1LL<<(k))
typedef long long ll;
typedef pair<int, int> i_i;
typedef pair<ll, ll> l_l;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;
template< typename T1, typename T2 >
ostream &operator<<(ostream &os, const pair< T1, T2 >& p) {
  os << "{" <<p.first << ", " << p.second << "}";
  return os;
}
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

const int INF = (ll)1e9;
const ll INFLL = (ll)1e18+1;
const ll MOD = (ll)1e9+7;
const double PI = acos(-1.0);
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const string dir = "DRUL";

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);
    ll H, W;
    cin >> H >> W;
    vector<string> S(H);
    rep(i,H)cin >> S[i];
    int sx, sy, gx, gy;
    rep(i,H)rep(j,W){
        if(S[i][j] == 's'){
            sx = i;
            sy = j;
        }
        if(S[i][j] == 'g'){
            gx = i;
            gy = j;
        }
    }
    auto isin = [&](int x, int y)->bool{
        return 0 <= x && x < H && 0 <= y && y < W;
    };
    // X以下の
    auto check = [&](ll X) -> bool {

    };
    vvec<bool> visited(H,vec<bool>(W,false));
    queue<pair<int,int>> q;
    q.push(make_pair(sx,sy));
    visited[sx][sy] = true;
    while(not q.empty()){
        auto p = q.front();
        q.pop();
        int x = p.first;
        int y = p.second;
        rep(i,4){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(not isin(nx,ny))continue;
            if(visited[nx][ny])continue;
            if(S[nx][ny] == '#')continue;
        }
    }
}
