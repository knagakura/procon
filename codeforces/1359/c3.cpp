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

void solve(){
    long double h, c, t;
    cin >> h >> c >> t;
    auto tmpa = [&](ll x) -> long double{
        long double res = x * h + (x - 1) * c;
        return res;
    };
    //回数の二分探索
    ll ok = 0;
    ll ng = INF;
    while(ng - ok > 1){
        ll mid = (ok + ng) / 2;
        long double tmp = tmpa(mid)/(2*mid - 1);
        if(tmp > t) {
            ok = mid;
        }
        else ng = mid;
    }
    long double diff = abs(tmpa(ok)/(2*ok - 1) - t);
    long double diff2 = abs(tmpa(ng)/(2*ng - 1) - t);
    long double diff3 = abs((h+c)/2 - t);
    ll ans = 0;
    long double minn = INF;
    if(diff <= diff2){
        ans = 2 * ok - 1;
        chmin(minn, diff);
    }
    else{
        ans = 2 * ng - 1;
        chmin(minn, diff2);
    }
    if(chmin(minn, diff3)){
        ans = 2;
    }
    cout << ans << endl;
}
int main() {
    int t;
    cin >> t;
    while(t --> 0)solve();
}