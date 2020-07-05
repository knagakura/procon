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

    ll N, p;
    cin >> N >> p;
    map<ll,ll> mp;
    vector<ll> a(N);
    rep(i, N){
        cin >> a[i];
        mp[a[i]]++;
    }
    sort(all(a));
    ll ok = INFLL;
    ll ng = 0;
    auto check = [&](ll X){
        int r = 0;
        for(int l = 0; l < N; l++){
            while(r < N && a[r] <= X){
                r++;
            }
            if((r - l) <= 0)return false;
            X++;
        }
        return true;
    };
    while(abs(ng - ok) > 1){
        ll mid = (ok + ng) >> 1;
        if(check(mid))ok = mid;
        else ng = mid;
    }
    ll ok2 = ok-1;
    ll ng2 = INFLL;
    auto check2 = [&](ll X){
        int r = 0;
        rep(l,N){
            while(r < N && a[r] <= X){
                r++;
            }
            if((r - l) % p == 0)return false;
            X++;
        }
        return true;
    };
    while(ng2 - ok2 > 1){
        ll mid = (ng2 + ok2) >> 1;
        if(check2(mid))ok2 = mid;
        else ng2 = mid;
    }
    cout << ok2 - ok + 1 << endl;
    for(ll ans = ok; ans <=ok2; ans++){
        cout << ans << " ";
    }
    cout << endl;
}