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

    long double x, y, h;
    cin >> x >> y >> h;
    
    h /= 1000;
    long double x2 = x, y2 = y, h2 = h;
    //x *= 1000;
    //y *= 1000;
    //cerr << x << " " << y << " " << h << endl;
    ll ans = 0;
    while(x > h){
        x /= 2;
        h *= 2;
        ans++;
        //cerr << x << " " << h <<endl;
    }
    while(y > h){
        y /= 2;
        h *= 2;
        ans++;
        //cerr << y << " " << h << endl;
    }


    ll ans2 = 0;
    while(x2 > h2){
        x2 /= 2;
        h2 *= 2;
        ans2++;
        //cerr << x << " " << h <<endl;
    }
    while(y2 > h2){
        y2 /= 2;
        h2 *= 2;
        ans2++;
        //cerr << y << " " << h << endl;
    }
    cout << min(ans, ans2) << endl;
}