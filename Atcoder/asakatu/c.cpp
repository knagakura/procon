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
    vector<pair<int, int>> a(3);
    int x[3];
    cin >> x[0] >> x[1] >> x[2];
    int mx = max({x[0], x[1], x[2]});
    int sum = (x[0] + x[1] + x[2]);
    a[0] = {x[0]%2, x[0]};
    a[1] = {x[1]%2, x[1]};
    a[2] = {x[2]%2, x[2]};
    sort(all(a));
    int ans = 0;
    //全部等しいとき 1 1 1, 0, 0, 0
    if(a[0].first == a[2].first){
        ans +=  (3 * mx - sum)/2;;
    }
    // 0, 1, 1
    else if(a[1].first == 1 && a[2].first ==  1){
        a[1].second += 1;
        a[2].second += 1;
        ans += 2;
        ans += (3 * max({a[0].second,a[1].second,a[2].second}) - (sum + 2))/2;;
    }
    // 0, 0, 1
    else if(a[0].first == a[1].first){
        a[0].second += 1;
        a[1].second += 1;
        ans += 2;
        ans +=  (3 * max({a[0].second,a[1].second,a[2].second}) - (sum + 2))/2;;
    }
    cout << ans << endl;
}