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
    ll T[2], A[2], B[2];
    rep(i,2)cin >> T[i];
    rep(i,2)cin >> A[i];
    rep(i,2)cin >> B[i];
    ll AM[2], BM[2];
    rep(j,2)AM[j] = A[j] * T[j];
    rep(j,2)BM[j] = B[j] * T[j];
    ll dist[2];
    rep(j,2)dist[j] = BM[j] - AM[j];
    // 最初の移動を+に変換
    if(dist[0] < 0){
        dist[0] = -dist[0];
        dist[1] = -dist[1];
    }
    // 繰り返す
    if(dist[0] + dist[1] == 0){
        cout << "infinity" << endl;
        return 0;
    }
    // 最初+で、次も+なら、ずっと+
    if(dist[0] > 0 && dist[0] + dist[1] > 0){
        cout << 0 << endl;
        return 0;
    }
    // print(AM);
    // print(BM);
    // print(dist);
    ll c = dist[0], d = dist[1];
    ll ans = abs(d) / abs(c + d)*2-1;
    if(abs(d) % abs(c+d) == 0)ans -= 1;
    cout << ans << endl;
}
