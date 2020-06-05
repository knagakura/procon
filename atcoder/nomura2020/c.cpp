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
ll power_pow(ll a, ll n) {
    ll res = 1;
    while (n > 0) {
        if (n & 1) res = res * a;
        a = a * a;
        n >>= 1;
    }
    return res;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    ll N;
    cin >> N;
    vec<ll> A(N+1);
    rep(i,N+1)cin >> A[i];
    vec<ll> MAXA(N+1);
    rep(i,N+1){
        ll tmp = power_pow(2, min(60,i));
        MAXA[i] = min(INFLL, tmp - 1);
    }
    rep(i,N+1){
        if(A[i] > MAXA[i]){
            cout << -1 << endl;
            return 0;
        }
    }
    if(A[N] == 0){
        cout << -1 << endl;
        return 0;
    }
    vec<int> cnt(N+1);
    cnt[N] = A[N];
    for(int i = N; i >= 1; i --){
        //A[i]とA[i-1]の関係
        //上で潰れる個数
        ll tmp = (cnt[i] + 1) / 2;
        cnt[i-1] = tmp + A[i-1];
        if(cnt[i-1] > MAXA[i]){
            cout << -1 << endl;
            return 0;
        }
    }
    print(A);
    print(MAXA);
    print(cnt);
    ll ans = 0;
    rep(i,N+1)ans += cnt[i];
    cout << ans << endl;
}

