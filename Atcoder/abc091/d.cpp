#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
#define rep1(i,N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define dump(x) cerr<<#x<<": "<<x<<endl;
#define bit(k) (1LL<<(k))
#define Yes "Yes"
#define No "No"
#define YES "YES"
#define NO "NO"
typedef long long ll;
template <class T> using vec = vector<T>;
template <class T> using vvec = vector<vec<T>>;

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

    int N;
    cin >> N;
    vector<ll> a(N);
    rep(i,N)cin>>a[i];
    vector<ll> b(N);
    rep(i,N)cin>>b[i];
    ll ans = 0;
    rep(k, 30){
        ll T = bit(k);
        vector<ll> amod(N);
        vector<ll> bmod(N);
        rep(i,N){
            amod[i] = a[i] % (2 * T);
            bmod[i] = b[i] % (2 * T);
        }
        sort(all(bmod));
        ll sum = 0;
        rep(i,N){
            // T <= a + b < 2T
            sum += lower_bound(all(bmod), 2 * T - amod[i]) - lower_bound(all(bmod), T - amod[i]);
            // 3T <= a + b < 4T
            sum += lower_bound(all(bmod), 4 * T - amod[i]) - lower_bound(all(bmod), 3 * T - amod[i]);
        }
        if(sum % 2 == 1)ans += T;
    }
    cout << ans << endl;
}