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

void Case(int t){
    cout << "Case #" << t << ": ";
}

void solve(){
    ll x, y;
    cin >> x >> y;
    ll ax = abs(x);
    ll ay = abs(y);
    if((ax & 1) == (ay & 1)){
        cout << "IMPOSSIBLE" << endl;
        return;
    }
    //全部+だと11111...1になる
    //i番目を-にすると、bit(i+1)が0になる。
    vec<int> pm(33,-1);
    for(int i = 0; i <= 32;i++){
        if(bit(i+1)>(ax + ay)){
            pm[i] = 1;
            break;
        }
        else if(bit(i+1) & (ax + ay)){
            pm[i] = 1;
        }
        else{
            pm[i] = 0;
        }
    }
    string dx = "WE";
    string dy = "SN";
    string ans = "";
    for(int i = 0; i <=32;i++){
        if(pm[i] == -1){
            break;
        }
        if(ax&bit(i)){
            ax += (pm[i]?-bit(i): bit(i));
            ans.push_back(dx[pm[i]]);
        }
        else{
            ay += (pm[i]?-(bit(i)): bit(i));
            ans.push_back(dy[pm[i]]);
        }
    }
    int sz = ans.size();
    if(x < 0){
        rep(i,sz){
            if(ans[i] == dx[0]) ans[i] = dx[1];
            else if(ans[i] == dx[1]) ans[i] = dx[0];
        }
    }
    if(y < 0){
        rep(i,sz){
            if(ans[i] == dy[0]) ans[i] = dy[1];
            else if(ans[i] == dy[1])ans[i] = dy[0];
        }
    }
    cout << ans << endl;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    for(int i = 1; i <= t; i++){
        Case(i);
        solve();
    }
}