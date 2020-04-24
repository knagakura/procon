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
    int N;
    cin >> N;
    vec<ll> a(N);
    vec<ll> v[2];
    rep(i,N){
        cin >> a[i];
        if(a[i] < 0)v[0].push_back(a[i]);
        else v[1].push_back(a[i]);
    }
    a.push_back(a.back());
    if((int)v[0].size() == N || (int)v[1].size() == N){
        cout << -1 << endl;
        return;
    }
    //符号が合っているか
    auto check = [&](int i){
        return (a[i-1] < 0 && a[i] < 0) || (a[i-1] > 0 && a[i] > 0);
    };
    ll ans = 0;
    for(int l = 0; l < N; ){
        int r = l + 1;
        while(check(r) && r + 1 <= N){
            r++;
        }
        ll add = -INF-1;
        for(int i = l; i < r; i++){
            chmax(add, a[i]);
        }
        ans += add;
        //dump(ans);
        l = r;
    }
    cout << ans << endl;
}
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);

    int t;
    cin >> t;
    while(t--)solve();
}