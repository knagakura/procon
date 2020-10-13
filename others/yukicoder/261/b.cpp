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
ll gcd(ll a,ll b){
    if(b == 0) return a;
    return gcd(b, a%b);
}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int N;
    cin >> N;
    vector<int> x(N), y(N);
    rep(i,N)cin>> x[i] >> y[i];
    auto solve = [&](int idx) -> int{
        map<i_i, int> map;
        //x[i], y[i]からの位置ベクトルの傾きで分類
        rep(i,N){
            if(i == idx)continue;
            int a = x[i] - x[idx];
            int b = y[i] - y[idx];
            if(a == 0 || b == 0){
                if(a == 0)b = 1;
                if(b == 0)a = 1;
                map[{a,b}]++;
                continue;
            }
            int g = gcd(abs(a), abs(b));
            a /= g;
            b /= g;
            map[{a,b}]++;
        }
        int res = 0;
        for(auto p: map){
            chmax(res, p.second+1);
        }
        return res;
    };
    int ans = 0;
    rep(i,N){
        chmax(ans, solve(i));
    }
    cout << ans << endl;
}