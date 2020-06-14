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
int N, M;
bool IsIn(int x,int y){
    return 0<=x&&x<N&&0<=y&&y<M;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    cin >> N >> M;
    vec<string> S(N);
    rep(i,N)cin >> S[i];
    int num = 0;
    rep(i,N)rep(j,M)num += S[i][j] == '#';
    if(num == 0){
        cout << 0 << endl;
        return 0;
    }
    if(num == N * M){
        cout << 1 << endl;
        return 0;
    }
    //*.*があるかどうか
    bool ok = true;
    rep(i,N){
        bool ch = false;
        int cnt = 0;
        rep(j,M-1){
            if(S[i][j] == '#' && S[i][j+1] == '.')ch = true;
            if(ch && S[i][j] != S[i][j+1]){
                cnt++;
            }
        }
        if(cnt >= 2)ok = false;
    }
    rep(j,M){
        bool ch = false;
        int cnt = 0;
        rep(i,N-1){
            if(S[i][j] == '#' && S[i+1][j] == '.')ch = true;
            if(ch && S[i][j] != S[i+1][j]){
                cnt++;
            }
        }
        if(cnt >= 2)ok = false;
    }
    if(!ok){
        cout << -1 << endl;
        return 0;
    }
    //ok
    int ans = 0;
    vvec<bool> visited(N,vec<bool>(M,false));
    auto bfs = [&](int i, int j) -> bool{
        visited[i][j] = true;
        queue<i_i> q;
        q.push({i,j});
        bool pushed = false;
        ans++;
        while(not q.empty()){
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            rep(k,4){
                int nx = x + dx[k];
                int ny = y + dy[k];
                if(not IsIn(nx, ny))continue;
                if(visited[nx][ny])continue;
                if(S[nx][ny] == '.')continue;
                pushed = true;
                visited[nx][ny] = true;
                q.push({nx, ny});
            }
        }
        return pushed;
    };
    int bad = 0;
    rep(i,N)rep(j,M){
        if(S[i][j] == '#' && not visited[i][j]){
            if(not bfs(i, j)){
                bad++;
            }
        }
    }
    if(bad == ans && ans > 0){
        cout << -1 << endl;
        return 0;
    }
    cout << ans << endl;
}