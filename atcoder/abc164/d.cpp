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

template<typename T, typename U> 
T modpow(T a, U n) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a % MOD;
        a = a * a % 2019;
        n >>= 1;
    }
    return res;
}
int main() {

    string S;
    cin >> S;
    int N = S.size();
    reverse(all(S));

    //指数の計算 繰り返し二乗法を使ってもよい
    vector<int> modpows(N);
    modpows[0] = 1;
    rep1(i,N)modpows[i] = (10*modpows[i-1])%2019;

    map<int, ll> mp;
    mp[0] = 1;
    ll tmp = 0;
    ll ans = 0;
    rep(i,N){
        tmp += (modpows[i]*(S[i]-'0'))%(2019);
        tmp %= 2019;
        if(i >= 3)ans += mp[tmp];
        mp[tmp]++;
    }
    cout << ans << endl;
}