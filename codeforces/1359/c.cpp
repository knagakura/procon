#include <bits/stdc++.h>

using namespace std;
#define rep(i, N) for(int i=0;i<int(N);++i)
#define rep1(i, N) for(int i=1;i<int(N);++i)
#define all(a) (a).begin(),(a).end()
#define print(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<_<<", "; cerr<<"]"<<endl; }
#define printpair(v) { cerr<<#v<<": [ "; for(auto _ : v) cerr<<"{"<<_.first<<","<<_.second<<"}"<<", "; cerr<<"]"<<endl; }
#define dump(x) cerr<<#x<<": "<<x<<endl;
#define bit(k) (1LL<<(k))
typedef long long ll;
typedef pair<int, int> i_i;
typedef pair<ll, ll> l_l;
template<class T> using vec = vector<T>;
template<class T> using vvec = vector<vec<T>>;

template<typename T1, typename T2>
ostream &operator<<(ostream &os, const pair<T1, T2> &p) {
    os << "{" << p.first << ", " << p.second << "}";
    return os;
}

template<class T>
inline bool chmax(T &a, T b) {
    if (a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if (a > b) {
        a = b;
        return true;
    }
    return false;
}

const int INF = (ll) 1e9;
const ll INFLL = (ll) 1e18 + 1;
const ll MOD = (ll) 1e9 + 7;
const double PI = acos(-1.0);

/*
const int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
const int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
const string dir = "DRUL";
*/

void solve() {
    long double h, c, t;
    cin >> h >> c >> t;
    auto tmpa = [&](ll x) -> long double {
        long double res = (long double)(x * h + (x - 1) * c) / (long double)(2 * x - 1);
        return res;
    };
    if (h + c >= 2 * t) {
        cout << 2 << endl;
        return;
    }
    //回数の二分探索
    ll ok = 0;
    ll ng = INF;
    while (ng - ok > 1) {
        ll mid = (ok + ng) / 2;
        if (tmpa(mid) > t) {
            ok = mid;
        } else ng = mid;
    }
    long double a = tmpa(ok);
    long double b = tmpa(ng);
    long double ave = (h + c) / 2;
    long double diff[] = {abs(a - t), abs(b - t), abs(ave - t)};
    cerr << ok << " " << ng << endl;
    print(diff);
    if (diff[2] < diff[0] && diff[2] < diff[1]) {
        cout << 2 << endl;
    } else if (diff[0] <= diff[1]) {
        cout << 2 * ok - 1 << endl;
    } else {
        cout << 2 * ng - 1 << endl;
    }
}

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int t;
    cin >> t;
    while (t-- > 0) {
        solve();
    }
}