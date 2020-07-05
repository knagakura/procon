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
    ll N, K;
    cin >> N >> K;
    vvec<int> v(N,vec<int>(N,0));
    int p = 0, q = 0;
    while(K--){
        cerr << p << " " << q << endl;
        v[p][q] = 1;
        p = (p + 1) % N;
        q = (q + 1) % N;
        if(p == 0)q = (q + 1) % N;
    }
    ll ans = 0;
    ll maxx = 0;
    ll minn = INFLL;
    rep(i,N){
        ll sum = 0;
        rep(j,N){
            sum += v[i][j];
        }
        chmax(maxx, sum);
        chmin(minn, sum);
    }
    ans += (maxx - minn) * (maxx - minn);
    maxx = 0;
    minn = INFLL;
    rep(j,N){
        ll sum = 0;
        rep(i,N){
            sum += v[i][j];
        }
        chmax(maxx, sum);
        chmin(minn, sum);
    }
    ans += (maxx - minn) * (maxx - minn);
    cout << ans << endl;
    rep(i,N){
        rep(j,N){
            cout << v[i][j];
        }
        cout << endl;
    }
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int t;
    cin >> t;
    while(t--)solve();
}
