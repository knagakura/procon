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

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    ll N, D, X, Y;
    cin >> N >> D >> X >> Y;
    X = abs(X);
    Y = abs(Y);
    if(X % D > 0 || Y % D > 0){
        cout << 0 << endl;
        return 0;
    }
    // XとYは両方Dの倍数
    ll cntX = X / D; // +Dの回数
    ll cntY = Y / D;

    long double kai = 1; // (1/4)^N
    rep(i,N)kai /= 4;
    vector<long double> fact(N+1);
    fact[0] = kai;
    rep(i,N)fact[i+1] = fact[i] * (i+1);
    long double ans = 0;
    for(ll i = cntX; i <= N; i++){
        for(ll j = cntY; j <= N; j++){
            ll k = i - cntX;
            ll l = j - cntY;
            if(i + j + k + l == N){
                //cerr << i << " " << j << " " << k << " " << l << endl;
                long double add = fact[N];
                add /= fact[i];
                add /= fact[j];
                add /= fact[k];
                add /= fact[l];
                rep(_,4)add *= kai;
                ans += add;
            }
        }
    }
    cout << ans << endl;
}
