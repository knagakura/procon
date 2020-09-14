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
int sx, sy, gx, gy;
int N;
bool intersect(double p1x, double p1y, double p2x, double p2y, double p3x, double p3y, double p4x, double p4y) {
    if (((p1x - p2x) * (p3y - p1y) + (p1y - p2y) * (p1x - p3x)) *
        ((p1x - p2x) * (p4y - p1y) + (p1y - p2y) * (p1x - p4x)) < 0) {
 
        if (((p3x - p4x) * (p1y - p3y) + (p3y - p4y) * (p3x - p1x)) *
            ((p3x - p4x) * (p2y - p3y) + (p3y - p4y) * (p3x - p2x)) < 0) {
            return true;
        }
 
    }
    return false;
}
int main() {

    cin >> sx >> sy >> gx >> gy >> N;
    vector<int> x(N), y(N);
    rep(i,N)cin >> x[i] >> y[i];
    int cnt = 0;
    rep(i,N){
        int j = (i + 1) % N;
        if(intersect(x[i], y[i], x[j], y[j], sx, sy, gx, gy)){
            cnt++;
        }
    }
    cout << cnt / 2 + 1 << endl;
}