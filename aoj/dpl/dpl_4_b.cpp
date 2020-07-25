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
const ll INFLL = (ll)1e17+1;
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

    int N, K;
    ll L,R;
    cin >> N >> K;
    cin >> L >> R;
    vector<ll> a(N);
    rep(i, N)cin >> a[i];
    sort(all(a));
    int l = N/2;
    int r = N - N/2;
    vector<pair<ll,ll>> v[2];
    map<pair<ll,ll>,ll> mp;
    for(int i = 0; i < bit(l);i++){
        ll sum = 0;
        ll cnt = __builtin_popcount(i);
        for(int j = 0; j < l; j++){
            if(i&bit(j))sum += a[j];
        }
        v[0].emplace_back(cnt, sum);
    }
    for(int i = 0; i < bit(r); i++){
        ll sum = 0;
        ll cnt = __builtin_popcount(i);
        for(int j = 0; j < r; j++){
            if(i&bit(j))sum += a[l+j];
        }
        v[1].emplace_back(cnt, sum);
        // mp[{sum,cnt}]++;
    }
    int sz = v[0].size();
    sort(all(v[1]));
    ll ans = 0;
    rep(i,sz){
        ll sum = v[0][i].second;
        ll cnt = v[0][i].first;
        ll add = upper_bound(all(v[1]), make_pair(K-cnt,R-sum))
                -lower_bound(all(v[1]), make_pair(K-cnt,L-sum));
        ans += add;
    }
    cout << ans << endl;
}
