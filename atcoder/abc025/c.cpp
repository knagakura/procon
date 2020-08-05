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
/*
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const string dir = "DRUL";
*/

int b[10][10], c[10][10];
int d[10][10];
bool visited[10];
// 順列が与えられるので、計算する
i_i calc(vector<int> &v){
    int sz = v.size();// = 9
    rep(i,sz){
        int x = v[i] % 3;
        int y = v[i] / 3;
        d[x][y] = i&1;
    }
    int l = 0, r = 0;
    rep(i,2)rep(j,3){
        if(d[i][j] == d[i+1][j])l += b[i][j];
        else r += b[i][j];
    }
    rep(i,3)rep(j,2){
        if(d[i][j] == d[i][j+1])l += c[i][j];
        else r += c[i][j];
    }
    return make_pair(l,r);
}
i_i dfs(vector<int> &v){
    if(v.size() == 9)return calc(v);
    int sz = v.size();
    int maxx = -1;
    i_i res;
    rep(i,9){
        if(visited[i])continue;
        v.emplace_back(i);
        visited[i] = true;
        auto p = dfs(v);
        int l = p.first;
        int r = p.second;
        v.pop_back();
        visited[i] = false;
        if(sz&1){ // lをmaxにする手を選ぶ
            if(chmax(maxx, r))res = p;
        }
        else{ // rをmaxにする手を選ぶ
            if(chmax(maxx,l))res = p; 
        }
    }
    return res;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    rep(i,2)rep(j,3)cin >> b[i][j];
    rep(i,3)rep(j,2)cin >> c[i][j];
    rep(i,10)visited[i] = false;
    vector<int> v;
    auto ans = dfs(v);
    cout << ans.first << endl;
    cout << ans.second << endl;
}
