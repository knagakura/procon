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

int N, Q;

void Case(int i){
    cout << "Case #" << i << ": ";
}
void solve(int i){
    cin >> N >> Q;
    map<int, vector<vector<int>>> mpr;
    map<int, vector<vector<int>>> mpc;
    vec<pair<int, int>> xy;
    vec<char> ds;
    rep(i,N){
        int a, b; char d;
        cin >> a >> b >> d;
        xy.push_back({a,b});
        ds.push_back(d);
        if(d == 'N' || d == 'S'){
            mpc[a].resize(2);
        }
        else{
            mpr[b].resize(2);
        }
    }
    rep(i,N){
        int x = xy[i].first;
        int y = xy[i].second;
        char d = ds[i];
        if(d == 'N')mpc[x][0].push_back(y);
        if(d == 'S')mpc[x][1].push_back(y);
        if(d == 'E')mpr[y][0].push_back(x);
        if(d == 'W')mpr[y][1].push_back(x);
    }
    map<int, int> maxc;
    map<int, int> maxr;
    
    for(auto px: mpc)for(auto py: mpr){

    }

}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        solve(i);
    }
}
